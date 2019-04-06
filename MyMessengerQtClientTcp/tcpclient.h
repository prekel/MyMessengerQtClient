#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
//#include <GetAccountByIdQuery.h>
#include <QJsonDocument>

class TcpClient
{
private:
	QTcpSocket *m_socket;
public:
	TcpClient();
	~TcpClient();

	void Connect(QString host, qint16 port);
	void Sample();
	QString Sample1(QString input);
};

#endif // TCPCLIENT_H
