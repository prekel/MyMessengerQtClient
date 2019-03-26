#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QJsonObject>
#include <QDateTime>

#include "Iso8601Time.h"

class Account
{
public:
	Account();

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
private:
	int AccountId;
	Iso8601Time *RegistrationDateTime;
	Iso8601Time *LoginDateTime;
	QString Nickname;
	//QVector<int> DialogsIds;
};

#endif // ACCOUNT_H
