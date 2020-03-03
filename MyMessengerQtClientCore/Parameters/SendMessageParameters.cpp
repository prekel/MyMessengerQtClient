#include "SendMessageParameters.h"

void SendMessageParameters::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["CommandName"].toInt());
	Token = json["Text"].toString();
	DialogId = json["DialogId"].toInt();
	Text = json["Text"].toString();
}

void SendMessageParameters::write(QJsonObject& json) const
{
	json["CommandName"] = CommandName;
	json["Token"] = Token;
	json["DialogId"] = DialogId;
	json["Text"] = Text;
}
