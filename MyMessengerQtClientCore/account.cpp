#include "account.h"

Account::Account()
{
	AccountId = 3;
	//RegistrationDateTime = nu;
	//LoginDateTime = QDateTime::currentDateTimeUtc();
}

void Account::read(const QJsonObject &json)
{
	AccountId = json["AccountId"].toInt();
	delete RegistrationDateTime;
	RegistrationDateTime = new Iso8601Time(json["RegistrationDateTime"].toString());
	delete LoginDateTime;
	LoginDateTime = new Iso8601Time(json["LoginDateTime"].toString());
}

void Account::write(QJsonObject &json) const
{
	json["AccountId"] = AccountId;
	json["RegistrationDateTime"] = RegistrationDateTime->ToString();
	json["LoginDateTime"] = LoginDateTime->ToString();
}
