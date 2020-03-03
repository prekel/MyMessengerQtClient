#ifndef QUERY_H
#define QUERY_H

#include <QJsonObject>
#include <QJsonArray>

#include "CommandType.h"
#include "AbstractParameters.h"
#include "IJsonSerializable.h"
#include "LoginParameters.h"
#include "GetAccountByIdParameters.h"
#include "CreateDialogParameters.h"
#include "GetDialogByIdParameters.h"
#include "RegisterParameters.h"
#include "SendMessageParameters.h"
#include "GetMessagesParameters.h"
#include "GetMessageLongPoolParameters.h"

class Query : public IJsonSerializable
{
public:
	Query() = default;
	AbstractParameters* Config;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

#endif // QUERY_H
