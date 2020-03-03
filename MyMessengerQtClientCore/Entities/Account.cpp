#include "Account.h"

void Account::read(const QJsonObject& json)
{
	AccountId = json["AccountId"].toInt();
	RegistrationDateTime = QDateTime::fromString(json["RegistrationDateTime"].toString(), Qt::DateFormat::ISODate);
	LoginDateTime = QDateTime::fromString(json["LoginDateTime"].toString(), Qt::DateFormat::ISODate);
	Nickname = json["Nickname"].toString();

	DialogsIds.clear();
	QJsonArray dialogs = json["DialogsIds"].toArray();
	for (auto i : dialogs) 
	{
		DialogsIds.append(i.toInt());
	}
}

void Account::write(QJsonObject& json) const
{
	json["AccountId"] = AccountId;
	json["RegistrationDateTime"] = RegistrationDateTime.toOffsetFromUtc(QDateTime::currentDateTime().offsetFromUtc()).toString(Qt::ISODateWithMs);
	json["LoginDateTime"] = LoginDateTime.toOffsetFromUtc(QDateTime::currentDateTime().offsetFromUtc()).toString(Qt::ISODateWithMs);
	json["Nickname"] = Nickname;

	QJsonArray ar;
	for (auto id : DialogsIds)
	{
		ar.append(id);
	}
	json["DialogsIds"] = ar;
}

//void Account::SetAccountId(int id)
//{
//	AccountId = id;
//}

//int Account::GetAccountId()
//{
//	return AccountId;
//}

//void Account::SetNickname(QString name)
//{
//	Nickname = name;
//}

//QString Account::GetNickname()
//{
//	return Nickname;
//}


//void Account::SetRegistrationDateTime(QDateTime date)
//{
//	RegistrationDateTime = date;
//}

//QDateTime Account::GetRegistrationDateTime()
//{
//	return RegistrationDateTime;
//}

//void Account::SetLoginDateTime(QDateTime date)
//{
//	LoginDateTime = date;
//}

//QDateTime Account::GetLoginDateTime()
//{
//	return LoginDateTime;
//}

////void Account::SetDialogsIds(QVector<int> v)
////{
////	DialogsIds = v;
////}

//QVector<int> Account::GetDialogsIds()
//{
//	return DialogsIds;
//}

