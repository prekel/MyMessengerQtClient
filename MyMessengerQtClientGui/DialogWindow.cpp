#include <QJsonDocument>
#include <QString>
#include <QFuture>
#include <QtConcurrent>

#include <TcpClient.h>
#include <Entities/Account.h>

#include <Responses/ResponseCode.h>

#include <Parameters/Query.h>
#include <Parameters/LoginParameters.h>
#include <Responses/LoginResponse.h>
#include <Parameters/GetAccountByIdParameters.h>
#include <Responses/GetAccountByIdResponse.h>
#include <Parameters/GetMessagesParameters.h>
#include <Responses/GetMessagesResponse.h>
#include <Parameters/SendMessageParameters.h>
#include <Responses/SendMessageResponse.h>
#include <Parameters/GetDialogByIdParameters.h>
#include <Responses/GetDialogByIdResponse.h>
#include <Parameters/GetMessageLongPoolParameters.h>
#include <Responses/GetMessageLongPoolResponse.h>

#include <IJsonSerializable.h>

#include "MainWindow.h"

#include "DialogWindow.h"
#include "ui_DialogWindow.h"

DialogWindow::DialogWindow(QWidget *parent, ConnectionConfig *conf) :
	QMainWindow(parent),
	ui(new Ui::DialogWindow)
{
	ui->setupUi(this);

	MembersNicknames = new QMap<int, QString>();
	Members = new QVector<Account*>();

	Conf = conf;
	this->setWindowTitle("DialogId: " + QString::number(Conf->DialogId) + "; Login: " + Conf->Login);

	QThread *threadSender = new QThread;
    TcpClient *mySender = new TcpClient();
    mySender->moveToThread(threadSender);
	connect(mySender, SIGNAL(receiveMessage(QString)), this, SLOT(callbackSendMessage(QString)));
	connect(this, SIGNAL(sendSendMessage(QString, quint16, QString)), mySender, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);
    threadSender->start();

	QThread *threadSender1 = new QThread;
	TcpClient *mySender1 = new TcpClient();
	mySender1->moveToThread(threadSender1);
	connect(mySender1, SIGNAL(receiveMessage(QString)), this, SLOT(callbackGetAccountById(QString)));
	connect(this, SIGNAL(sendGetAccountById(QString, quint16, QString)), mySender1, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);
	threadSender1->start();

	QThread *threadSender2 = new QThread;
	TcpClient *mySender2 = new TcpClient();
	mySender2->moveToThread(threadSender2);
	connect(mySender2, SIGNAL(receiveMessage(QString)), this, SLOT(callbackGetDialogById(QString)));
	connect(this, SIGNAL(sendGetDialogById(QString, quint16, QString)), mySender2, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);
	threadSender2->start();


	QThread *threadReceiver = new QThread;
	TcpClient *myReceiver = new TcpClient();
	myReceiver->moveToThread(threadReceiver);
	connect(myReceiver, SIGNAL(receiveMessage(QString)), this, SLOT(callbackGetMessageLongPool(QString)));
	connect(this, SIGNAL(sendGetMessageLongPool(QString, quint16, QString)), myReceiver, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);
	threadReceiver->start();
	receiveDialogMembers();
}

DialogWindow::~DialogWindow()
{
	delete ui;
}

void DialogWindow::callbackSendMessage(QString i)
{
	SendMessageResponse resp;
	resp.FromJsonString(i);

	if (resp.Code == ResponseCode::Ok)
	{

	}
	else if (resp.Code == ResponseCode::AccessDenied)
	{
		ui->textBrowser->append(" --- Access denied --- ");
	}
	else
	{
		ui->textBrowser->append(" --- Error code : " + QString::number(resp.Code) + " --- ");
	}
}

void DialogWindow::callbackGetMessageLongPool(QString i)
{
	GetMessageLongPoolResponse resp;
	resp.FromJsonString(i);

	if (resp.Code == ResponseCode::Ok)
	{
		auto name = MembersNicknames->value(resp.Content->AuthorId);
		auto text = resp.Content->Text;
		ui->textBrowser->append(name + ": " + text);
		receiveLongPool();
	}
	else if (resp.Code == ResponseCode::AccessDenied)
	{
		ui->textBrowser->append(" --- Access denied --- ");
	}
	else if (resp.Code == ResponseCode::LongPoolTimeSpanExpired)
	{
		receiveLongPool();
	}
	else
	{
		ui->textBrowser->append(" --- Error code : " + QString::number(resp.Code) + " --- ");
	}

}

void DialogWindow::on_pushButton_send_clicked()
{
	SendMessageParameters p;
    p.Text = ui->plainTextEdit->toPlainText();
	p.Token = Conf->Token;
	p.DialogId = Conf->DialogId;
    p.CommandName = CommandType::SendMessage;
    Query q;
    q.Config = &p;

    auto s1 = q.ToJsonString();
	emit sendSendMessage(Conf->Host, Conf->Port, s1);
}

void DialogWindow::receiveLongPool()
{
	GetMessageLongPoolParameters p;
	p.Token = Conf->Token;
	p.TimeSpan = QTime(0, 0, 25);
	p.DialogId = Conf->DialogId;
    p.CommandName = CommandType::GetMessageLongPool;
    Query q;
    q.Config = &p;

    auto s1 = q.ToJsonString();
	emit sendGetMessageLongPool(Conf->Host, Conf->Port, s1);
}


void DialogWindow::callbackGetAccountById(QString i)
{
	auto r = new GetAccountByIdResponse();
	r->FromJsonString(i);

	auto a = r->_Account;

	Members->append(a);
	MembersNicknames->insert(a->AccountId, a->Nickname);

	if (Members->count() == _Dialog->MembersIds.count())
	{
		receiveLongPool();
	}
}

void DialogWindow::callbackGetDialogById(QString i)
{
	auto r = new GetDialogByIdResponse();
	r->FromJsonString(i);

	_Dialog = r->m_Dialog;

	for (auto j : _Dialog->MembersIds)
	{
		GetAccountByIdParameters p;
		p.Token = Conf->Token;
		p.AccountId = j;
		p.CommandName = CommandType::GetAccountById;
		Query q;
		q.Config = &p;
		auto s = q.ToJsonString();
		emit sendGetAccountById(Conf->Host, Conf->Port, s);
	}
}

void DialogWindow::receiveDialogMembers()
{
	GetDialogByIdParameters p;
	p.Token = Conf->Token;
	p.DialogId = Conf->DialogId;
	p.CommandName = CommandType::GetDialogById;
	Query q;
	q.Config = &p;
	auto s = q.ToJsonString();
	emit sendGetDialogById(Conf->Host, Conf->Port, s);
}
