#include "account.h"

Account::Account()
{
	AccountId = 3;
	RegistrationDateTime = QDateTime::currentDateTime();
	LoginDateTime = QDateTime::currentDateTimeUtc();
}

void Account::read(const QJsonObject &json)
{
	AccountId = json["AccountId"].toInt();
	//RegistrationDateTime = json["RegistrationDateTime"];
	//LoginDateTime = json["LoginDateTime"];
}

void Account::write(QJsonObject &json) const
{
	json["AccountId"] = AccountId;
	json["RegistrationDateTime"] = RegistrationDateTime.toString(Qt::ISODate);
	json["LoginDateTime"] = LoginDateTime.toString(Qt::ISODate);
}
