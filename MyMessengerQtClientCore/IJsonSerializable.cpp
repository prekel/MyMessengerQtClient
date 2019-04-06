#include "IJsonSerializable.h"

QString IJsonSerializable::ToJsonString(QJsonDocument::JsonFormat format)
{
	QJsonObject ob;
	write(ob);

	QJsonDocument doc(ob);

	QString s(doc.toJson(format));

	return s;
}

void IJsonSerializable::FromJsonString(QString s)
{
	QJsonDocument doc = QJsonDocument::fromJson(s.toUtf8());
	read(doc.object());
}
