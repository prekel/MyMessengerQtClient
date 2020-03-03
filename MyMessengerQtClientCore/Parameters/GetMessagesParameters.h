#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "AbstractParameters.h"

class GetMessagesParameters : public AbstractParameters
{
public:
	GetMessagesParameters() = default;

	int DialogId;
	QString Token;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
