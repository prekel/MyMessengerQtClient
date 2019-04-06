#include "GetAccountByIdResponse.h"

//GetAccountByIdResponse::GetAccountByIdResponse()
//{

//}

void GetAccountByIdResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	Account.read(json["Account"].toObject());
}

void GetAccountByIdResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	QJsonObject ob;
	Account.write(ob);
	json["Account"] = ob;
}
