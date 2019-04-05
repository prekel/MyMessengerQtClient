#include "GetAccountByIdQuery.h"

GetAccountByIdQuery::GetAccountByIdQuery()
{
}

GetAccountByIdQuery::~GetAccountByIdQuery()
{
}

void GetAccountByIdQuery::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["Config"]["CommandName"].toInt());
	Token = json["Config"]["Token"].toInt();
	Token = json["AccountId"]["AccountId"].toInt();
}

void GetAccountByIdQuery::write(QJsonObject& json) const
{
	QJsonObject config;
	config["CommandName"] = CommandName;
	config["Token"] = Token;
	config["AccountId"] = AccountId;
	json["Config"] = config;
}