#ifndef DIALOG_H
#define DIALOG_H

#include <QJsonObject>
#include <QDateTime>
#include <QVector>
#include <QJsonArray>

#include "IJsonSerializable.h"

class Dialog : public IJsonSerializable
{
public:
	Dialog();

	void read(const QJsonObject &json) override;
	void write(QJsonObject &json) const override;

	int DialogId;

	QVector<int> MembersIds;
};

#endif // DIALOG_H
