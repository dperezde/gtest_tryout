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

TEST(AddTest,Handle_big_numbers)
{
	EXPECT_EQ(500,Add("100,250,140,10"));
	EXPECT_EQ(1000,Add("100,500,300,100"));
	EXPECT_EQ(1000,Add("1000"));
	EXPECT_EQ(0,Add("1001"));
	EXPECT_EQ(2,Add("1001,2"));
	EXPECT_EQ(500,Add("501,300,300,200,100,100"));
}

TEST(AddTest, HandleManyNumberInput)
{
	EXPECT_EQ(3,Add("1,1,1"));
	EXPECT_EQ(11,Add("1,1,1,1,1,1,1,1,1,1,1"));
	EXPECT_EQ(120,Add("10,10,10,10,20,20,5,5,5,5,5,5,5,5"));
}

TEST(AddTest, negative_numbers)
{
	ASSERT_ANY_THROW(Add("1,-1"));
}
TEST(AddTest, HandleNewLine)
{
	EXPECT_EQ(2,Add("1\n1"));
	EXPECT_EQ(3,Add("1,1\n1"));
	EXPECT_EQ(15,Add("1,10\n3,1"));
}


TEST(AddTest, HandleNewDelimiter)
{
	ASSERT_EQ(2,Add("//;\n1;1"));
//	ASSERT_EQ(0,Add("//;1;1"));
	ASSERT_ANY_THROW(Add("//;1;1"));

//	ASSERT_EQ(0,Add("//-|-\n1-|-1-|-3-|-5-|-5"));
	ASSERT_ANY_THROW(Add("//-|-\n1-|-1-|-3-|-5-|-5"));

	ASSERT_EQ(15,Add("//[-|-]\n1-|-1-|-3-|-5-|-5"));
	EXPECT_EQ(20,Add("//[..][$¡]\n1..1$¡3$¡3$¡2..4..4$¡1..1"));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

