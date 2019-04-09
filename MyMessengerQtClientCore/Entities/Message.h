#ifndef MESSAGE_H
#define MESSAGE_H

#include <QJsonObject>
#include <QDateTime>
#include <QVector>
#include <QJsonArray>

#include "IJsonSerializable.h"

class Message : public IJsonSerializable
{
public:
	Message();

	void read(const QJsonObject &json) override;
	void write(QJsonObject &json) const override;

	int MessageId;

	QString Text;

	QDateTime SendDateTime;

	int DialogId;

	int AuthorId;
};

#endif // MESSAGE_H
