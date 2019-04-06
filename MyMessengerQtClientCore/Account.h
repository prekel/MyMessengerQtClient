#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QJsonObject>
#include <QDateTime>
#include <QVector>
#include <QJsonArray>

#include "Iso8601Time.h"

class Account
{
public:
	Account();

	//void SetAccountId(int id);
	//int GetAccountId();
	//void SetNickname(QString name);
	//QString GetNickname();

	//void SetRegistrationDateTime(QDateTime date);
	//QDateTime GetRegistrationDateTime();
	//void SetLoginDateTime(QDateTime date);
	//QDateTime GetLoginDateTime();

	//void SetDialogsIds(QVector<int> v);
	//QVector<int> GetDialogsIds();

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;

	QVector<int> DialogsIds;
//private:
	int AccountId;
	QDateTime RegistrationDateTime;
	QDateTime LoginDateTime;
	QString Nickname;

	//Iso8601Time DateTime;
};

#endif // ACCOUNT_H
