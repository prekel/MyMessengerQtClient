#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "IJsonSerializable.h"
#include "ResponseCode.h"

class AbstractResponse : public IJsonSerializable
{
public:
	AbstractResponse() = default;
	virtual ~AbstractResponse() = default;

	ResponseCode Code;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};
