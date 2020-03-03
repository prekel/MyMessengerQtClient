#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "AbstractParameters.h"

class GetDialogByIdParameters : public AbstractParameters
{
public:
	GetDialogByIdParameters() = default;

	QString Token;
	int DialogId;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
