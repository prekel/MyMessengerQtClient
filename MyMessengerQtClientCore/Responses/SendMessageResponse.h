#pragma once

#include "AbstractResponse.h"

class SendMessageResponse : public AbstractResponse
{
public:
	SendMessageResponse() = default;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

