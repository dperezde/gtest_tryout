#include <limits.h>
#include "gtest/gtest.h"
#include "Multiply.hpp"

class MultiplyTest : public ::testing::Test {
protected:
	virtual void SetUp(){
	}

	virtual void TearDown(){
    // Code here will be called immediately after each test
    // (right before the destructor).
	}
};

TEST_F(MultiplyTest,twoValues){
	const int x = 4;
	const int y = 5;
	Multiply multiply;
	EXPECT_EQ(9,multiply.twoValues(x,y));
	EXPECT_EQ(5,multiply.twoValues(2,3));

}


