#include "LoginParameters.h"


//LoginParameters::LoginParameters()
//{
//}

void LoginParameters::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["CommandName"].toInt());
	Nickname = json["Nickname"].toString();
	Password = json["Password"].toString();
}

void LoginParameters::write(QJsonObject& json) const
{
	json["CommandName"] = CommandName;
	json["Nickname"] = Nickname;
	json["Password"] = Password;
}
