#include "GetMessagesParameters.h"

void GetMessagesParameters::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["CommandName"].toInt());
	Token = json["Token"].toString();
	DialogId = json["DialogId"].toInt();
}

void GetMessagesParameters::write(QJsonObject& json) const
{
	json["CommandName"] = CommandName;
	json["Token"] = Token;
	json["DialogId"] = DialogId;
}
