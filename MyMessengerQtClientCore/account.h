#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QJsonObject>
#include <QDateTime>

#include "Iso8601Time.h"

class Account
{
public:
	Account();

	void SetAccountId(int id);
	int GetAccountId();
	void SetNickname(QString name);
	QString GetNickname();
	void SetRegistrationDateTime(Iso8601Time date);
	Iso8601Time GetRegistrationDateTime();
	void SetLoginDateTime(Iso8601Time date);
	Iso8601Time GetLoginDateTime();

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
private:
	int AccountId;
	QString RegistrationDateTime;
	QString LoginDateTime;
	QString Nickname;
	//QVector<int> DialogsIds;
};

#endif // ACCOUNT_H
