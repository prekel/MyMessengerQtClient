#include "tst_testcase1.h"
#include "Iso8601TimeTests.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
