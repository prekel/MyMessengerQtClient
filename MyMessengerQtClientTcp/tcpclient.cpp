#include "tcpclient.h"

TcpClient::TcpClient()
{
	m_socket = new QTcpSocket();
}

TcpClient::~TcpClient()
{
	delete m_socket;
}

void TcpClient::Connect(QString host, qint16 port)
{
	//m_socket->connectToHost("51.158.73.185", 20522);
	m_socket->connectToHost(host, port);
}

void TcpClient::Sample()
{
	if(m_socket->waitForConnected(5000))
	{
		qDebug() << "Connected!";

		// send
		m_socket->write("Hello server\r\n\r\n");
		//m_socket->write();
		m_socket->waitForBytesWritten(1000);
		m_socket->waitForReadyRead(3000);

		qDebug() << "Reading: " << m_socket->bytesAvailable();

		// get the data
		qDebug() << m_socket->readAll();

		// close the connection
		m_socket->close();
	}
	else
	{
		qDebug() << "Not connected!";
	}
}
