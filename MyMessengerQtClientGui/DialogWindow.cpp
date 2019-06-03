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

#include "DialogWindow.h"
#include "ui_DialogWindow.h"

DialogWindow::DialogWindow(QWidget *parent, QString ip, int port, QString token) :
	QMainWindow(parent),
	ui(new Ui::DialogWindow)
{
	ui->setupUi(this);
    this->ip = ip;
    this->port = port;
    this->token = token;

    QThread *threadSender = new QThread;
    TcpClient *mySender = new TcpClient();

    mySender->moveToThread(threadSender);

    connect(mySender, SIGNAL(receiveMessage(QString)), this, SLOT(update1(QString)));

    connect(this, SIGNAL(connectToServer1(QString, qint16)), mySender, SLOT(connectToServer(QString, qint16)), Qt::AutoConnection);
    connect(this, SIGNAL(sendMessage1(QString)), mySender, SLOT(sendMessage(QString)), Qt::AutoConnection);

    threadSender->start();

    QThread *threadReceiver = new QThread;
    TcpClient *myReceiver = new TcpClient();

    myReceiver->moveToThread(threadReceiver);

    connect(myReceiver, SIGNAL(receiveMessage(QString)), this, SLOT(update2(QString)));

    connect(this, SIGNAL(connectToServer2(QString, qint16)), myReceiver, SLOT(connectToServer(QString, qint16)), Qt::AutoConnection);
    connect(this, SIGNAL(sendMessage2(QString)), myReceiver, SLOT(sendMessage(QString)), Qt::AutoConnection);

    threadReceiver->start();
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
    ui->textBrowser->append(i);
}

void DialogWindow::on_pushButton_clicked()
{
    emit connectToServer1(ip, port);

    SendMessageParameters p;
    p.Text = ui->plainTextEdit->toPlainText();
    p.Token = token;
    p.DialogId = 1;
    p.CommandName = CommandType::SendMessage;
    Query q;
    q.Config = &p;

    auto s1 = q.ToJsonString();
    emit sendMessage1(s1);
}

void DialogWindow::on_pushButton_2_clicked()
{
    emit connectToServer2(ip, port);

    GetMessageLongPoolParameters p;
    p.Token = token;
    p.TimeSpan = QTime(0,0,25);
    p.DialogId = 1;
    p.CommandName = CommandType::GetMessageLongPool;
    Query q;
    q.Config = &p;

    auto s1 = q.ToJsonString();
    emit sendMessage2(s1);
}
