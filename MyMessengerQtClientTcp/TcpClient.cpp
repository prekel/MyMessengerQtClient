#include "TcpClient.h"

TcpClient::TcpClient()
{
    //m_socket = new QTcpSocket();
}

TcpClient::~TcpClient()
{
    //delete m_socket;
}

//void TcpClient::Connect(QString host, qint16 port)
//{
	//m_socket->connectToHost("51.158.73.185", 20522);
    //m_socket->connectToHost(host, port);
//}

//QString ToJson(const GetAccountByIdQuery a)
//{
//	QJsonObject ob;
//	a.write(ob);

//	QJsonDocument doc(ob);

//	QString s(doc.toJson(QJsonDocument::Indented));

//	//auto a1 = Account();
//	GetAccountByIdQuery a1;
//	a1.read(ob);

//	return s;
//}

//void TcpClient::doWork()
//{
//    for(int i = 0; i <= 100; i++)
//    {
//        emit send(i);
//        QThread::sleep(1);
//    }
//}

void TcpClient::sendString(QString host, quint16 port, QString message)
{
    auto socket = new QTcpSocket();
    socket->connectToHost(host, port);

    if (socket->waitForConnected(5000))
    {
        qDebug() << "Connected!";

        socket->write(message.toUtf8());
        //m_socket->waitForBytesWritten(1000);
        //m_socket->waitForReadyRead(3000);
        socket->waitForBytesWritten();
        socket->waitForReadyRead();

        qDebug() << "Reading: " << socket->bytesAvailable();

        auto output = socket->readAll();

        socket->close();

        emit receiveMessage(QString::fromUtf8(output));
    }
    else
    {
        qDebug() << "Not connected!";
        //return "";
    }
}

//void TcpClient::Sample()
//{
//	//auto q = GetAccountByIdQuery();
//	//q.AccountId = 2;
//	//q.Token = 7881;
//	//q.CommandName = CommandType::GetAccountById;
//	//auto s = ToJson(q);

//	if (m_socket->waitForConnected(5000))
//	{
//		qDebug() << "Connected123!";

//		// send
//		//m_socket->write("Hello server\r\n\r\n");
//		m_socket->write("s.toUtf8()");
//		//m_socket->write();
//		m_socket->waitForBytesWritten(1000);
//		m_socket->waitForReadyRead(3000);

//		qDebug() << "Reading: " << m_socket->bytesAvailable();

//		// get the data
//		qDebug() << m_socket->readAll();

//		// close the connection
//		m_socket->close();
//	}
//	else
//	{
//		qDebug() << "Not connected!";
//	}
//}

//QString TcpClient::Sample1(QString input)
//{
//	if (m_socket->waitForConnected(5000))
//	{
//		qDebug() << "Connected!";

//		m_socket->write(input.toUtf8());
//		//m_socket->waitForBytesWritten(1000);
//		//m_socket->waitForReadyRead(3000);
//		m_socket->waitForBytesWritten();
//		m_socket->waitForReadyRead();

//		qDebug() << "Reading: " << m_socket->bytesAvailable();

//		auto output = m_socket->readAll();

//		m_socket->close();

//		return QString::fromUtf8(output);
//	}
//	else
//	{
//		qDebug() << "Not connected!";
//		return "";
//	}
//}
