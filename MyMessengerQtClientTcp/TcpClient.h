#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
#include <QJsonDocument>
#include <QObject>
#include <QString>
#include <QThread>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    TcpClient();
	~TcpClient();

public slots:
	void sendString(QString host, quint16 port, QString message);
signals:
    void receiveMessage(QString message);

private:
};

#endif // TCPCLIENT_H
