#include "stdafx.h"
#include "MemLeakTest.h"

MemLeakTest::MemLeakTest()
{
}


MemLeakTest::~MemLeakTest()
{
}

TEST_F(MemLeakTest, primoTest)
{
	ASSERT_EQ(1, 1);
}