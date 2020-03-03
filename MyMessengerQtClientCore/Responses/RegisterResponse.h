#pragma once

#include "AbstractResponse.h"

class RegisterResponse : public AbstractResponse
{
public:
	RegisterResponse() = default;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

