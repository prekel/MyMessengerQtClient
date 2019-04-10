#include "GetAccountByIdResponse.h"

void GetAccountByIdResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	_Account.read(json["Account"].toObject());
}

void GetAccountByIdResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	QJsonObject ob;
	_Account.write(ob);
	json["Account"] = ob;
}
