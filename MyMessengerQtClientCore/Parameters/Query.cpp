#include "Query.h"

void Query::read(const QJsonObject& json)
{
	auto type = static_cast<CommandType>(json["Config"]["CommandName"].toInt());

	if (type == CommandType::GetMessages)
	{
		GetMessagesParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::Register)
	{
		RegisterParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::Login)
	{
		LoginParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::SendMessage)
	{
		SendMessageParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::CreateDialog)
	{
		CreateDialogParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::GetMessageLongPool)
	{
		GetMessageLongPoolParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::GetAccountById)
	{
		GetAccountByIdParameters a;
		a.read(json["Config"].toObject());
		Config = &a;
	}
	if (type == CommandType::GetDialogById)
	{
		GetDialogByIdParameters a;
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
