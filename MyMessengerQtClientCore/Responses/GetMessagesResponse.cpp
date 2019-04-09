#include "LoginResponse.h"

//LoginResponse::LoginResponse()
//{
//}

void LoginResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	Token = json["Token"].toString();

	Account.read(json["Account"].toObject());
}

void LoginResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	json["Token"] = Token;

	QJsonObject ob;
	Account.write(ob);
	json["Account"] = ob;
}
