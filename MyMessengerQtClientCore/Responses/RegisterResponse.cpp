#include "RegisterResponse.h"

void RegisterResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());
}

void RegisterResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;
}
