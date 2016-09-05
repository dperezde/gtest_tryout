#include <iostream>

#include "gtest/gtest.h"
#include "my.hpp"

/* Tests that Empty string returns 0 */
TEST(AddTest,HandlesZeroInput)
{
	EXPECT_EQ(0,Add(""));
}

TEST(AddTest,HandlesSingleNumberInput)
{
	EXPECT_EQ(1,Add("1"));
	EXPECT_EQ(2,Add("2"));

	EXPECT_EQ(10,Add("10"));

}


TEST(AddTest,HandleTwoNumberInput)
{
	EXPECT_EQ(2,Add("1,1"));
	EXPECT_EQ(15,Add("5,10"));

}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

