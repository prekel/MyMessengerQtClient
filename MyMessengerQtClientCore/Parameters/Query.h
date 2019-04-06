#ifndef QUERY_H
#define QUERY_H

#include <QJsonObject>
#include <QJsonArray>

#include "CommandType.h"
#include "AbstractParameters.h"
#include "LoginParameters.h"
#include "GetAccountByIdParameters.h"

class Query
{
public:
	Query() = default;
	AbstractParameters* Config;

	void read(const QJsonObject& json);
	void write(QJsonObject& json) const;
};

#endif // QUERY_H
