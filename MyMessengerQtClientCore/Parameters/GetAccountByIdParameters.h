#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "CommandType.h"
#include "AbstractParameters.h"

class GetAccountByIdParameters : public AbstractParameters
{
public:
	GetAccountByIdParameters() = default;

public:
	QString Token;
	int AccountId;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
