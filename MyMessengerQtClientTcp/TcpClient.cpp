#include "TcpClient.h"

TcpClient::TcpClient()
{
}

TcpClient::~TcpClient()
{
}

void TcpClient::sendString(QString host, quint16 port, QString message)
{
	auto socket = new QTcpSocket();
	socket->connectToHost(host, port);

	if (socket->waitForConnected(5000))
	{
		socket->write(message.toUtf8());

		socket->waitForBytesWritten();
		socket->waitForReadyRead();


		auto output = socket->readAll();

		socket->close();

		emit receiveMessage(QString::fromUtf8(output));
	}
	else
	{
	}
}
