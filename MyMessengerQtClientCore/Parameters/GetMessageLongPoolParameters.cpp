#include "GetMessageLongPoolParameters.h"

void GetMessageLongPoolParameters::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["CommandName"].toInt());
	Token = json["Token"].toString();
	DialogId = json["DialogId"].toInt();

	TimeSpan = QTime::fromString(json["TimeSpan"].toString(), "hh:mm:ss");
}

void GetMessageLongPoolParameters::write(QJsonObject& json) const
{
	json["CommandName"] = CommandName;
	json["Token"] = Token;

	json["DialogId"] = DialogId;

	json["TimeSpan"] = TimeSpan.toString("hh:mm:ss");
}
