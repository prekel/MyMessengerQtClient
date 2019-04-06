#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "Parameters/CommandType.h"
#include "Parameters/AbstractParameters.h"

class GetAccountByIdParameters : public AbstractParameters
{
public:
	GetAccountByIdParameters();

public:
	int Token;
	int AccountId;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
