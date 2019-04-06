#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <Account.h>

using namespace testing;

TEST(TestCase1, TestSet1)
{
	EXPECT_EQ(1, 1);
	ASSERT_THAT(0, Eq(0));
}

TEST(TestCase1, TestSet2)
{
	auto a = new Account();
	EXPECT_EQ(1, 1);
	ASSERT_THAT(0, Eq(0));
	delete a;
}
