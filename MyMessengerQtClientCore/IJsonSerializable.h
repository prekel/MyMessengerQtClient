#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QString>

class IJsonSerializable
{
public:
	IJsonSerializable() = default;
	virtual ~IJsonSerializable() = default;

	virtual void read(const QJsonObject& json) = 0;
	virtual void write(QJsonObject& json) const = 0;

	QString ToJsonString(QJsonDocument::JsonFormat format = QJsonDocument::Indented);
	//static IJsonSerializable FromJsonString();

	void FromJsonString(QString s);
};

#endif // IJSONSERIALIZABLE_H
