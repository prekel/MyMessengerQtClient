#pragma once

#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QVector>

#include "AbstractParameters.h"

class CreateDialogParameters : public AbstractParameters
{
public:
	CreateDialogParameters() = default;

	QString Token;

	QVector<QString> *MembersNicknames;
	QVector<int> *MembersIds;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
