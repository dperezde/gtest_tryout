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

TEST(AddTest, HandleManyNumberInput)
{
	EXPECT_EQ(3,Add("1,1,1"));
	EXPECT_EQ(11,Add("1,1,1,1,1,1,1,1,1,1,1"));
	EXPECT_EQ(120,Add("10,10,10,10,20,20,5,5,5,5,5,5,5,5"));
}

TEST(AddTest, HandleNewLine)
{
	EXPECT_EQ(2,Add("1\n1"));
	EXPECT_EQ(3,Add("1,1\n1"));
	EXPECT_EQ(15,Add("1,10\n3,1"));
}


TEST(AddTest, HandleNewDelimiter)
{
	EXPECT_EQ(2,Add("//;\n1;1"));
	EXPECT_EQ(0,Add("//;1;1"));
	EXPECT_EQ(15,Add("//-|-\n1-|-1-|-3-|-5-|-5"));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

