#include "RegisterParameters.h"

void RegisterParameters::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["CommandName"].toInt());
	Nickname = json["Nickname"].toString();
	Password = json["Password"].toString();
}

void RegisterParameters::write(QJsonObject& json) const
{
	json["CommandName"] = CommandName;
	json["Nickname"] = Nickname;
	json["Password"] = Password;
}
