#include "GetMessagesResponse.h"

void GetMessagesResponse::read(const QJsonObject& json)
{
	Code = static_cast<ResponseCode>(json["Code"].toInt());

	Content.clear();
	QJsonArray ar = json["Content"].toArray();
	for (auto i : ar)
	{
		auto ob = i.toObject();
		auto m = Message();
		m.read(ob);
		Content.append(m);
	}
}

void GetMessagesResponse::write(QJsonObject& json) const
{
	json["Code"] = Code;

	QJsonArray ar;
	for (auto id : Content)
	{
		QJsonObject ob;
		id.write(ob);
		ar.append(ob);
	}
	json["Content"] = ar;
}
