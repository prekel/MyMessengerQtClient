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

	Conf = conf;
	this->setWindowTitle("DialogId: " + QString::number(Conf->DialogId) + "; Login: " + Conf->Login);

    QThread *threadSender = new QThread;
    TcpClient *mySender = new TcpClient();

    mySender->moveToThread(threadSender);

    connect(mySender, SIGNAL(receiveMessage(QString)), this, SLOT(update1(QString)));
	connect(this, SIGNAL(sendMessage1(QString, quint16, QString)), mySender, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);

    threadSender->start();

	QThread *threadReceiver = new QThread;
	TcpClient *myReceiver = new TcpClient();

	myReceiver->moveToThread(threadReceiver);

	connect(myReceiver, SIGNAL(receiveMessage(QString)), this, SLOT(update2(QString)));
	connect(this, SIGNAL(sendMessage2(QString, quint16, QString)), myReceiver, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);

	threadReceiver->start();

	on_pushButton_2_clicked();
}

DialogWindow::~DialogWindow()
{
	delete ui;
}

void DialogWindow::update1(QString i)
{

}

void DialogWindow::update2(QString i)
{
    GetMessageLongPoolResponse lresp;
    lresp.FromJsonString(i);

    if (lresp.Code == ResponseCode::Ok)
	{
        auto name = QString::number(lresp.Content.AuthorId);
        auto text = lresp.Content.Text;
        ui->textBrowser->append(name + ": " + text);
    }

    on_pushButton_2_clicked();
}

void DialogWindow::on_pushButton_clicked()
{
	//emit connectToServer1(Conf->Host, Conf->Port);

    SendMessageParameters p;
    p.Text = ui->plainTextEdit->toPlainText();
	p.Token = Conf->Token;
	p.DialogId = Conf->DialogId;
    p.CommandName = CommandType::SendMessage;
    Query q;
    q.Config = &p;

    auto s1 = q.ToJsonString();
	emit sendMessage1(Conf->Host, Conf->Port, s1);
}

void DialogWindow::on_pushButton_2_clicked()
{
	//emit connectToServer1(Conf->Host, Conf->Port);

    GetMessageLongPoolParameters p;
	p.Token = Conf->Token;
	p.TimeSpan = QTime(0, 0, 25);
    p.DialogId = 1;
    p.CommandName = CommandType::GetMessageLongPool;
    Query q;
    q.Config = &p;

    auto s1 = q.ToJsonString();
	emit sendMessage2(Conf->Host, Conf->Port, s1);
}
