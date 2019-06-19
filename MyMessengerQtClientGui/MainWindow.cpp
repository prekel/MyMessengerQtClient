#include <QJsonDocument>
#include <QString>
#include <QFuture>
#include <QtConcurrent>

#include <TcpClient.h>
#include <Entities/Account.h>

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
#include <Parameters/CreateDialogParameters.h>
#include <Responses/CreateDialogResponse.h>

#include <IJsonSerializable.h>

#include "ConnectionConfig.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);


	m_JsonModel = new QJsonModel(this);

	QThread *thread= new QThread;
	TcpClient *my = new TcpClient();
	my->moveToThread(thread);
	connect(my, SIGNAL(receiveMessage(QString)), this, SLOT(callbackLoginRegister(QString)));
	connect(this, SIGNAL(sendLoginRegister(QString, quint16, QString)), my, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);
	thread->start();

	QThread *threadCreateDialog= new QThread;
	TcpClient *myCreateDialog = new TcpClient();
	myCreateDialog->moveToThread(threadCreateDialog);
	connect(myCreateDialog, SIGNAL(receiveMessage(QString)), this, SLOT(callbackCreateDialog(QString)));
	connect(this, SIGNAL(sendCreateDialog(QString, quint16, QString)), myCreateDialog, SLOT(sendString(QString, quint16, QString)), Qt::AutoConnection);
	threadCreateDialog->start();
}

MainWindow::~MainWindow()
{
	delete m_JsonModel;
	delete ui;
}

void MainWindow::callbackLoginRegister(QString resp)
{
	LoginResponse lresp;
	lresp.FromJsonString(resp);

	ui->lineEdit_token->setText(lresp.Token);

    ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());
}

void MainWindow::callbackCreateDialog(QString resp)
{
	CreateDialogResponse lresp;
	lresp.FromJsonString(resp);

	ui->lineEdit_dialogid->setText(QString::number(lresp.DialogId));

	ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());
}

void MainWindow::on_pushButton_login_clicked()
{
	LoginParameters p;
    p.Nickname = ui->lineEdit_login->text();
    p.Password = ui->lineEdit_password->text();
    p.CommandName = CommandType::Login;
    Query q;
    q.Config = &p;

    auto s1 = q.ToJsonString();
	emit sendLoginRegister(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toUShort(), s1);
}

void MainWindow::on_pushButton_openDialog_clicked()
{
	auto conf = new ConnectionConfig();
	conf->Host = ui->lineEdit_serverip->text();
	conf->Port = ui->lineEdit_serverport->text().toUShort();
	conf->Token = ui->lineEdit_token->text();
	conf->DialogId = ui->lineEdit_dialogid->text().toInt();
	conf->Login = ui->lineEdit_login->text();
	auto dialog1 = new DialogWindow(this, conf);
	dialog1->show();
	delete conf;
}

void MainWindow::on_pushButton_register_clicked()
{
	RegisterParameters p;
	p.Nickname = ui->lineEdit_login->text();
	p.Password = ui->lineEdit_password->text();
	p.CommandName = CommandType::Register;
	Query q;
	q.Config = &p;

	auto s1 = q.ToJsonString();
	emit sendLoginRegister(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toUShort(), s1);
}

void MainWindow::on_pushButton_createDialog_clicked()
{
	CreateDialogParameters p;
	p.Token = ui->lineEdit_token->text();

	p.MembersIds = new QVector<int>();
	auto idsstr = ui->lineEdit_membersIds->text().split(",");
	if (idsstr.count() > 1)
	{
		for (auto i : idsstr)
		{
			p.MembersIds->append(i.trimmed().toInt());
		}
	}

	p.MembersNicknames = new QVector<QString>();
	auto nicks = ui->lineEdit_membersNicknames->text().split(",");
	if (nicks.count() > 1)
	{
		for (auto i : nicks)
		{
			p.MembersNicknames->append(i.trimmed());
		}
	}

	p.CommandName = CommandType::CreateDialog;

	Query q;
	q.Config = &p;

	auto s1 = q.ToJsonString();
	emit sendCreateDialog(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toUShort(), s1);
}
