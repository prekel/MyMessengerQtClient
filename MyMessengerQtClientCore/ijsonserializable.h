#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <QJsonObject>

class IJsonSerializable
{
public:
	IJsonSerializable();

	virtual void read(const QJsonObject &json) = 0;
	virtual void write(QJsonObject &json) const = 0;
};

#endif // IJSONSERIALIZABLE_H
