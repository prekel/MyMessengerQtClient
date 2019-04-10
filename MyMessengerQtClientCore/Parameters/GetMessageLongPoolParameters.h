#pragma once

#include <QJsonObject>
#include <QJsonArray>
#include <QTime>

#include "AbstractParameters.h"

class GetMessageLongPoolParameters : public AbstractParameters
{
public:
	GetMessageLongPoolParameters() = default;

	int DialogId;
	QString Token;
	QTime TimeSpan;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
