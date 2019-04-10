#include "LoginResponse.h"

void LoginResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	Token = json["Token"].toString();

	m_Account.read(json["Account"].toObject());
}

void LoginResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	json["Token"] = Token;

	QJsonObject ob;
	m_Account.write(ob);
	json["Account"] = ob;
}
