#include "SendMessageResponse.h"

void SendMessageResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());
}

void SendMessageResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;
}
