#include "GetDialogByIdResponse.h"

void GetDialogByIdResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	m_Dialog = new Dialog();
	m_Dialog->read(json["Dialog"].toObject());
}

void GetDialogByIdResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	QJsonObject ob;
	m_Dialog->write(ob);
	json["Dialog"] = ob;
}
