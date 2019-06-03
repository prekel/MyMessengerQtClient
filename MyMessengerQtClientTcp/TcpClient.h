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

    void Connect(QString host, qint16 port);
    void Sample();
	QString Sample1(QString input);

public slots:
    void connectToServer(QString host, qint16 port);
    void sendMessage(QString message);
signals:
    void receiveMessage(QString message);

private:
    QTcpSocket *m_socket;
};

#endif // TCPCLIENT_H
