#pragma once

#include <QString>

#include "AbstractResponse.h"
#include "Entities/Account.h"

class CreateDialogResponse : public AbstractResponse
{
public:
	CreateDialogResponse() = default;

	int DialogId;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

