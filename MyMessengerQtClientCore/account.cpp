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
	RegistrationDateTime = QDateTime::fromString(json["RegistrationDateTime"].toString());
	LoginDateTime = QDateTime::fromString(json["LoginDateTime"].toString());
}

void Account::write(QJsonObject &json) const
{
	json["AccountId"] = AccountId;
	json["RegistrationDateTime"] = RegistrationDateTime.toOffsetFromUtc(QDateTime::currentDateTime().offsetFromUtc()).toString(Qt::ISODate);
	json["LoginDateTime"] = LoginDateTime.toOffsetFromUtc(QDateTime::currentDateTime().offsetFromUtc()).toString(Qt::ISODate);
}
