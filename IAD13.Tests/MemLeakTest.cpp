#include "stdafx.h"
#include "gtest\gtest.h"
#include <memory>

using namespace std;

TEST(MemLeakTest, ShouldLeakMemory)
{
	int *i = new int[1];
	i[0] = 10;
	cout << i[0] << endl;
	//delete i;
}