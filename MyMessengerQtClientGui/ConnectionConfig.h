#ifndef CONNECTIONCONFIG_H
#define CONNECTIONCONFIG_H

#include <QString>

class ConnectionConfig
{
public:
    ConnectionConfig() = default;
public:
    QString Host;
    qint16 Port;
    QString Token;
    int DialogId;
};

#endif // CONNECTIONCONFIG_H
