#include <QJsonDocument>
#include <QString>

#include <tcpclient.h>
#include <Account.h>

#include <Parameters/Query.h>
#include <Parameters/LoginParameters.h>
#include <Responses/LoginResponse.h>
#include <Parameters/GetAccountByIdParameters.h>
#include <Responses/GetAccountByIdResponse.h>

#include <IJsonSerializable.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

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


QString ToJson(const Account a)
{
	QJsonObject ob;
	a.write(ob);

	QJsonDocument doc(ob);

	QString s(doc.toJson(QJsonDocument::Indented));

	//auto a1 = Account();
	Account a1;
	a1.read(ob);

	return s;
}

Account FromJson(QString s)
{
	Account a; 
	QJsonDocument doc = QJsonDocument::fromJson(s.toUtf8());
	a.read(doc.object());
	return a;
}

void MainWindow::on_pushButton_2_clicked()
{
	Account a;
	a.AccountId = 4;
	a.RegistrationDateTime = QDateTime::currentDateTime();
	a.LoginDateTime = QDateTime::currentDateTime().addDays(2);
	a.DialogsIds.append(2);
	a.DialogsIds.append(3);
	a.Nickname = "User4";

	auto s = a.ToJsonString();

	qDebug() << s;

	//Account b = FromJson(s);

	//auto a1 = Account();
}

void MainWindow::on_pushButton_login_clicked()
{
	auto client = TcpClient();
	client.Connect("51.158.73.185", 20522);
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

	ui->label_token->setText(lresp.Token);
}

void MainWindow::on_pushButton_gabid_clicked()
{
	auto client = TcpClient();
	client.Connect("51.158.73.185", 20522);
	GetAccountByIdParameters p;
	p.AccountId = ui->lineEdit_accountid->text().toInt();
	p.Token = ui->label_token->text();
	p.CommandName = CommandType::GetAccountById;
	Query q;
	q.Config = &p;

	auto s1 = q.ToJsonString();
	auto resp = client.Sample1(s1);

	GetAccountByIdResponse lresp;
	lresp.FromJsonString(resp);

	//ui->label_token->setText(lresp.Token);
}
