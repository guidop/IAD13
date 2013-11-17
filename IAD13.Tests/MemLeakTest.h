#pragma once
#include "gtest\gtest.h"

class MemLeakTest : public ::testing::Test
{
public:
	MemLeakTest();
	~MemLeakTest();
};

