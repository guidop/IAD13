#pragma once
#include "..\IAD13\CryptRandomNumberGenerator.h"
#include "gtest\gtest.h"

class CryptRandomNumberGeneratorTest : public ::testing::Test
{
public:
	void SetUp();
	void TearDown();
protected:
	CryptRandomNumberGenerator m_cryptRandomNumberGenerator;
	int m_numAttempt;
	int m_lengthByteArray;
};

