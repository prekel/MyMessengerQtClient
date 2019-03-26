#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QJsonObject>
#include <QDateTime>

class Account
{
public:
	Account();

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
private:
	int AccountId;
	QDateTime RegistrationDateTime;
	QDateTime LoginDateTime;
	QString Nickname;
	//QVector<int> DialogsIds;
};

#endif // ACCOUNT_H
