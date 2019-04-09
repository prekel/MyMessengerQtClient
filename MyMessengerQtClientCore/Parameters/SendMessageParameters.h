#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "AbstractParameters.h"

class SendMessageParameters : public AbstractParameters
{
public:
	SendMessageParameters() = default;

	QString Token;
	int DialogId;
	QString Text;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
