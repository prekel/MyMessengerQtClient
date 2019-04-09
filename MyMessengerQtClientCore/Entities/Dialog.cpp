#include "Dialog.h"

Dialog::Dialog()
{
	DialogId = 0;
}


void Dialog::read(const QJsonObject& json)
{
	DialogId = json["DialogId"].toInt();

	MembersIds.clear();
	QJsonArray members = json["MembersIds"].toArray();
	for (auto i : members)
	{
		MembersIds.append(i.toInt());
	}
}

void Dialog::write(QJsonObject& json) const
{
	json["DialogId"] = DialogId;

	QJsonArray ar;
	for (auto id : MembersIds)
	{
		ar.append(id);
	}
	json["MembersIds"] = ar;
}
