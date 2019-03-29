#include "account.h"

Account::Account()
{
	//AccountId = 3;
}

void Account::read(const QJsonObject &json)
{
	AccountId = json["AccountId"].toInt();
	RegistrationDateTime = json["RegistrationDateTime"].toString();
	LoginDateTime = json["LoginDateTime"].toString();
	Nickname = json["Nickname"].toString();
}

void Account::write(QJsonObject &json) const
{
	json["AccountId"] = AccountId;
	json["RegistrationDateTime"] = RegistrationDateTime;
	json["LoginDateTime"] = LoginDateTime;
	json["Nickname"] = Nickname;
}

void Account::SetAccountId(int id)
{
	AccountId = id;
}

int Account::GetAccountId()
{
	return AccountId;
}

void Account::SetNickname(QString name)
{
	Nickname = name;
}

QString Account::GetNickname()
{
	return Nickname;
}

void Account::SetRegistrationDateTime(Iso8601Time date)
{
	RegistrationDateTime = date.ToString();
}

Iso8601Time Account::GetRegistrationDateTime()
{
	return Iso8601Time::FromString(RegistrationDateTime);
}

void Account::SetLoginDateTime(Iso8601Time date)
{
	LoginDateTime = date.ToString();
}

Iso8601Time Account::GetLoginDateTime()
{
	return Iso8601Time::FromString(LoginDateTime);
}
