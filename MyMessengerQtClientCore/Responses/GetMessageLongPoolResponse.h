#pragma once

#include <QString>

#include "AbstractResponse.h"
#include "Entities/Message.h"

class GetMessageLongPoolResponse : public AbstractResponse
{
public:
	GetMessageLongPoolResponse() = default;
	~GetMessageLongPoolResponse() override;

	Message* Content;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

