#ifndef CONNECTIONCONFIG_H
#define CONNECTIONCONFIG_H

#include <QString>

class ConnectionConfig
{
public:
	ConnectionConfig() = default;
public:
	QString Host;
	quint16 Port;
	QString Token;
	int DialogId;
	QString Login;
};

#endif // CONNECTIONCONFIG_H
