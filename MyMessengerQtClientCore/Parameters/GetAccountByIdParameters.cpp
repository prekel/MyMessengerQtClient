#include "GetAccountByIdParameters.h"

//GetAccountByIdParameters::GetAccountByIdParameters()
//{
//}

//GetAccountByIdParameters::~GetAccountByIdParameters()
//{
//}

void GetAccountByIdParameters::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["CommandName"].toInt());
	Token = json["Token"].toInt();
	Token = json["AccountId"].toInt();
}

void GetAccountByIdParameters::write(QJsonObject& json) const
{
	json["CommandName"] = CommandName;
	json["Token"] = Token;
	json["AccountId"] = AccountId;
}
