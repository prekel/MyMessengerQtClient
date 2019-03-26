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

	auto a1 = Account();
	a1.read(ob);

	return s;
}
void MainWindow::on_pushButton_2_clicked()
{
	auto a = Account();

	auto s = ToJson(a);

	qDebug() << s;

	auto a1 = Account();
}
