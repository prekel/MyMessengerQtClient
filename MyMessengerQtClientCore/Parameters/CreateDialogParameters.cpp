#include "CreateDialogParameters.h"

void CreateDialogParameters::read(const QJsonObject& json)
{
	CommandName = static_cast<CommandType>(json["CommandName"].toInt());

	Token = json["Token"].toString();

	MembersIds = new QVector<int>();
	QJsonArray ar = json["MembersIds"].toArray();
	for (auto i : ar)
	{
		MembersIds->append(i.toInt());
	}

	MembersNicknames = new QVector<QString>();
	QJsonArray ar1 = json["MembersNicknames"].toArray();
	for (auto i : ar1)
	{
		MembersNicknames->append(i.toString());
	}
}

void CreateDialogParameters::write(QJsonObject& json) const
{
	json["CommandName"] = CommandName;
	json["Token"] = Token;

	QJsonArray ar;
	for (auto i : *MembersIds)
	{
		ar.append(i);
	}
	json["MembersIds"] = ar;

	QJsonArray ar1;
	for (auto i1 : *MembersNicknames)
	{
		ar1.append(i1);
	}
	json["MembersNicknames"] = ar1;
}
