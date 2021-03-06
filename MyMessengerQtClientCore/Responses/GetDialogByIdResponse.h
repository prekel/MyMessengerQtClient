#pragma once

#include <QString>

#include "AbstractResponse.h"
#include "Entities/Dialog.h"

class GetDialogByIdResponse : public AbstractResponse
{
public:
	GetDialogByIdResponse() = default;
	~GetDialogByIdResponse() override;

	Dialog* m_Dialog;

	void read(const QJsonObject& json) override;
	void write(QJsonObject& json) const override;
};

