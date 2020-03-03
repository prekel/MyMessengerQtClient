#pragma once

#include <QString>
#include <QVector>

#include "AbstractResponse.h"
#include "Entities/Message.h"

class GetMessagesResponse : public AbstractResponse
{
public:
	GetMessagesResponse() = default;

	QVector<Message> Content;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

