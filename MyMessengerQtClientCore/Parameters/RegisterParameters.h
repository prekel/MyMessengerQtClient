#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "AbstractParameters.h"

class RegisterParameters : public AbstractParameters
{
public:
	RegisterParameters() = default;

	QString Nickname;
	QString Password;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
