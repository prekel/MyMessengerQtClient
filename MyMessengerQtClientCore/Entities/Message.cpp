#include "Message.h"

void Message::read(const QJsonObject& json)
{
	MessageId = json["MessageId"].toInt();
	DialogId = json["DialogId"].toInt();
	AuthorId = json["AuthorId"].toInt();

	Text = json["Text"].toString();

	SendDateTime = QDateTime::fromString(json["SendDateTime"].toString(), Qt::DateFormat::ISODate);
}

void Message::write(QJsonObject& json) const
{
	json["MessageId"] = MessageId;
	json["DialogId"] = DialogId;
	json["AuthorId"] = AuthorId;

	json["Text"] = Text;

	json["SendDateTime"] = SendDateTime.toOffsetFromUtc(QDateTime::currentDateTime().offsetFromUtc()).toString(Qt::ISODateWithMs);
}
