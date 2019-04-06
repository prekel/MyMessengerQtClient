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

	//virtual void read(const QJsonObject& json) = 0;
	//virtual void write(QJsonObject& json) const = 0;
};
