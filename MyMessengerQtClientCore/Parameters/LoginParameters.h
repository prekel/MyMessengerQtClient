#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "AbstractParameters.h"

class LoginParameters : public AbstractParameters
{
public:
	LoginParameters() = default;

	QString Nickname;
	QString Password;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
