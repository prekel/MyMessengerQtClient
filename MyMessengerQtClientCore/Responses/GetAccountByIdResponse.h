#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "AbstractResponse.h"
#include "ResponseCode.h"
#include "Entities/Account.h"

class GetAccountByIdResponse : public AbstractResponse
{
public:
	GetAccountByIdResponse() = default;

	Account Account;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

