#ifndef GETACCOUNTBYIIDRESPONSE_H
#define GETACCOUNTBYIIDRESPONSE_H

#include "responsecode.h"
#include "account.h"

class GetAccountByIdResponse
{
public:
	GetAccountByIdResponse();
private:
	Account m_Account;
	ResponseCode m_Code;
};

#endif // GETACCOUNTBYIIDRESPONSE_H
