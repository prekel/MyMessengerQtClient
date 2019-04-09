#include "CreateDialogResponse.h"

void CreateDialogResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	DialogId = json["DialogId"].toInt();
}

void CreateDialogResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	json["DialogId"] = DialogId;
}
