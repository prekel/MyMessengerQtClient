#include "GetMessageLongPoolResponse.h"

void GetMessageLongPoolResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	Content.read(json["Content"].toObject());
}

void GetMessageLongPoolResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	QJsonObject ob;
	Content.write(ob);
	json["Content"] = ob;
}
