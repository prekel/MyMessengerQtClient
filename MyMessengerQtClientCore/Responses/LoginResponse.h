#pragma once

#include <QString>

#include "AbstractResponse.h"
#include "Entities/Account.h"

class LoginResponse : public AbstractResponse
{
public:
	LoginResponse() = default;

	QString Token;
	Account m_Account;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

