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

#include <IJsonSerializable.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	auto client = TcpClient();
	client.Connect("51.158.73.185", 20522);
	client.Sample();
}


//QString ToJson(const Account a)
//{
//	QJsonObject ob;
//	a.write(ob);
//
//	QJsonDocument doc(ob);
//
//	QString s(doc.toJson(QJsonDocument::Indented));
//
//	//auto a1 = Account();
//	Account a1;
//	a1.read(ob);
//
//	return s;
//}
//
//Account FromJson(QString s)
//{
//	Account a; 
//	QJsonDocument doc = QJsonDocument::fromJson(s.toUtf8());
//	a.read(doc.object());
//	return a;
//}

void MainWindow::on_pushButton_2_clicked()
{
	//Account a;
	//a.AccountId = 4;
	//a.RegistrationDateTime = QDateTime::currentDateTime();
	//a.LoginDateTime = QDateTime::currentDateTime().addDays(2);
	//a.DialogsIds.append(2);
	//a.DialogsIds.append(3);
	//a.Nickname = "User4";

	//auto s = a.ToJsonString();

	//qDebug() << s;

	//Account b = FromJson(s);

	//auto a1 = Account();

	QFuture<QString> future = QtConcurrent::run([=]() {
		auto client = TcpClient();
		client.Connect(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toInt());

		LoginParameters p;
		p.Nickname = ui->lineEdit_login->text();
		p.Password = ui->lineEdit_password->text();
		p.CommandName = CommandType::Login;
		Query q;
		q.Config = &p;

		auto s1 = q.ToJsonString();
		auto resp = client.Sample1(s1);


		return resp;
	});

	auto resp = future.result();

	LoginResponse lresp;
	lresp.FromJsonString(resp);

	ui->lineEdit_token->setText(lresp.Token);

	delete m_JsonModel;
	m_JsonModel = new QJsonModel();
	ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());

	ui->lcdNumber->display(lresp.Code);
}

void MainWindow::on_pushButton_login_clicked()
{
	auto client = TcpClient();
	client.Connect(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toInt());

	LoginParameters p;
	p.Nickname = ui->lineEdit_login->text();
	p.Password = ui->lineEdit_password->text();
	p.CommandName = CommandType::Login;
	Query q;
	q.Config = &p;

	auto s1 = q.ToJsonString();
	auto resp = client.Sample1(s1);

	LoginResponse lresp;
	lresp.FromJsonString(resp);

	ui->lineEdit_token->setText(lresp.Token);

	delete m_JsonModel;
	m_JsonModel = new QJsonModel();
	ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());

	ui->lcdNumber->display(lresp.Code);
}

void MainWindow::on_pushButton_gabid_clicked()
{
	auto client = TcpClient();
	client.Connect(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toInt());

	GetAccountByIdParameters p;
	p.AccountId = ui->lineEdit_accountid->text().toInt();
	p.Token = ui->lineEdit_token->text();
	p.CommandName = CommandType::GetAccountById;
	Query q;
	q.Config = &p;

	auto query = q.ToJsonString();
	auto resp = client.Sample1(query);

	GetAccountByIdResponse lresp;
	lresp.FromJsonString(resp);

	delete m_JsonModel;
	m_JsonModel = new QJsonModel();
	ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());

	ui->lcdNumber->display(lresp.Code);
}

void MainWindow::on_pushButton_getmessages_clicked()
{
	auto client = TcpClient();
	client.Connect(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toInt());

	GetMessagesParameters p;
	p.DialogId = ui->lineEdit_dialogid->text().toInt();
	p.Token = ui->lineEdit_token->text();
	p.CommandName = CommandType::GetMessages;
	Query q;
	q.Config = &p;

	auto query = q.ToJsonString();
	auto resp = client.Sample1(query);

	GetMessagesResponse lresp;
	lresp.FromJsonString(resp);

	delete m_JsonModel;
	m_JsonModel = new QJsonModel();
	ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());

	ui->lcdNumber->display(lresp.Code);
}

void MainWindow::on_pushButton_sendmessage_clicked()
{
	auto client = TcpClient();
	client.Connect(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toInt());

	SendMessageParameters p;
	p.DialogId = ui->lineEdit_dialogid->text().toInt();
	p.Token = ui->lineEdit_token->text();
	p.Text = ui->lineEdit_text->text();
	p.CommandName = CommandType::SendMessage;
	Query q;
	q.Config = &p;

	auto query = q.ToJsonString();
	auto resp = client.Sample1(query);

	SendMessageResponse lresp;
	lresp.FromJsonString(resp);

	delete m_JsonModel;
	m_JsonModel = new QJsonModel();
	ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());

	ui->lcdNumber->display(lresp.Code);
}

void MainWindow::on_pushButton_gdbid_clicked()
{
	auto client = TcpClient();
	client.Connect(ui->lineEdit_serverip->text(), ui->lineEdit_serverport->text().toInt());

	GetDialogByIdParameters p;
	p.DialogId = ui->lineEdit_dialogid->text().toInt();
	p.Token = ui->lineEdit_token->text();
	p.CommandName = CommandType::GetDialogById;
	Query q;
	q.Config = &p;

	auto query = q.ToJsonString();
	auto resp = client.Sample1(query);

	GetDialogByIdResponse lresp;
	lresp.FromJsonString(resp);

	delete m_JsonModel;
	m_JsonModel = new QJsonModel();
	ui->treeView->setModel(m_JsonModel);
	m_JsonModel->loadJson(resp.toUtf8());

	ui->lcdNumber->display(lresp.Code);
}

void MainWindow::on_pushButton_openDialog_clicked()
{
	QFuture<int> future = QtConcurrent::run([=]() {
		for (auto i = 0; i < INT_MAX / 3; i++)
		{
			if (i % 1000000 == 0)
			{
				qDebug() << i;
			}
		}
		return 1;
	});
	auto dialog1 = new DialogWindow(this);
	dialog1->show();
}
