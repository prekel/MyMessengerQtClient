#ifndef ABSTRACTPARAMETERS_H
#define ABSTRACTPARAMETERS_H

#include <QJsonObject>
#include <QJsonArray>

#include "CommandType.h"

class AbstractParameters
{
public:
	AbstractParameters() = default;
	virtual ~AbstractParameters() = default;

	CommandType CommandName;

	virtual void read(const QJsonObject& json) = 0;
	virtual void write(QJsonObject& json) const = 0;
};

#endif // ABSTRACTPARAMETERS_H
