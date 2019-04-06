#include "Query.h"

//Query::Query()
//{

//}

void Query::read(const QJsonObject& json)
{
	auto type = static_cast<CommandType>(json["Config"]["CommandName"].toInt());
	if (type == CommandType::Login)
	{
		LoginParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::GetAccountById)
	{
		GetAccountByIdParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
}

void Query::write(QJsonObject& json) const
{
	//auto type = Config->CommandName;
	QJsonObject conf;
	Config->write(conf);
	json["Config"] = conf;
//	if (type == CommandType::Login)
//	{
//		LoginParameters a;
//		a.write(conf);
//	}
//	if (type == CommandType::GetAccountById)
//	{
//		GetAccountByIdParameters a;
//		a.read(conf);
//	}
//	json["Config"] = conf;
}
