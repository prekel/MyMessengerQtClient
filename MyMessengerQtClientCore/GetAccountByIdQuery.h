#pragma once

#include <QJsonObject>
#include <QJsonArray>
#include "commandname.h"

class GetAccountByIdQuery 
{
public:
	GetAccountByIdQuery();
	~GetAccountByIdQuery();

public:
	CommandType CommandName;
	int Token;
	int AccountId;

	void read(const QJsonObject& json);
	void write(QJsonObject& json) const;
};
