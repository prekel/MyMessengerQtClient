#ifndef ACCOUNTTESTS_H
#define ACCOUNTTESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "Account.h"

TEST(AccountTests, Test1)
{
	auto a = Account();
	//a.SetAccountId(1);
	//a.SetNickname("User1");
	//a.SetLoginDateTime(QDateTime::fromSecsSinceEpoch(1553610607));
	//a.SetRegistrationDateTime(QDateTime::fromSecsSinceEpoch(1553610607));

	auto offset = 7 * 60 * 60;
	//EXPECT_EQ(1, a.GetAccountId());
	//EXPECT_EQ("User1", a.GetNickname());
	//EXPECT_EQ("2019-03-26T21:30:07.000+07:00", a.GetLoginDateTime().toOffsetFromUtc(QDateTime::currentDateTime().offsetFromUtc()).toString(Qt::ISODateWithMs));
	//EXPECT_EQ("2019-03-26T21:30:07.000+07:00", a.GetRegistrationDateTime().toOffsetFromUtc(QDateTime::currentDateTime().offsetFromUtc()).toString(Qt::ISODateWithMs));
}

#endif // ACCOUNTTESTS_H
