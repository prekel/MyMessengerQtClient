#include "AbstractResponse.h"

//AbstractResponse::AbstractResponse()
//{

//}

//AbstractResponse::~AbstractResponse() = default;

void AbstractResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());
}

void AbstractResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;
}
