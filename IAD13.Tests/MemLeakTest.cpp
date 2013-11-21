#include "stdafx.h"
#include "gtest\gtest.h"
#include <memory>

using namespace std;

TEST(MemLeakTest, ShouldNotLeakMemory)
{
	auto i = new int{ 10 };
	cout << *i << endl;
//	delete i;
}