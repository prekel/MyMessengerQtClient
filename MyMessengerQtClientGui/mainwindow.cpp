#include <QJsonDocument>
#include <QString>

#include <tcpclient.h>
#include <account.h>

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
	a.SetAccountId(4);
	a.SetRegistrationDateTime(QDateTime::currentDateTime());
	a.SetLoginDateTime(QDateTime::currentDateTime().addDays(2));
	a.DialogsIds.append(2);
	a.DialogsIds.append(3);
	a.SetNickname("User1");

	auto s = ToJson(a);

	qDebug() << s;

	Account b = FromJson(s);

	//auto a1 = Account();
}
