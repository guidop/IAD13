#include "CryptRandomNumberGeneratorTest.h"
#include "..\IAD13\Timer.h"
#include <string>
#include <Windows.h>


using namespace std;

void CryptRandomNumberGeneratorTest::SetUp()
{
	m_numAttempt = 100;
	m_lengthByteArray = 2;
}
void CryptRandomNumberGeneratorTest::TearDown()
{
}

//con 10000 tentativi e 2 byte, RNG_ALGORITHM e RNG_FIPS186_DSA_ALGORITHM impiegano lo stesso tempo
//RNG_DUAL_EC_ALGORITHM invece impiega più di 100 volte di più :-/
TEST_F(CryptRandomNumberGeneratorTest, GenerateRandomNumber_RNG_ALGORITHM)
{
	wstring result1, result2;
	CTimer timer;
	timer.Start();
	for (int i = 0; i < m_numAttempt; i++)
	{
		result1 = m_cryptRandomNumberGenerator.Generate(BCRYPT_RNG_ALGORITHM, m_lengthByteArray);
		result2 = m_cryptRandomNumberGenerator.Generate(BCRYPT_RNG_ALGORITHM, m_lengthByteArray);
		ASSERT_NE(result1, result2);
	}
	timer.Stop();
}

TEST_F(CryptRandomNumberGeneratorTest, GenerateRandomNumber_RNG_DUAL_EC_ALGORITHM)
{
	wstring result1, result2;
	CTimer timer;
	timer.Start();
	for (int i = 0; i < m_numAttempt; i++)
	{
		result1 = m_cryptRandomNumberGenerator.Generate(BCRYPT_RNG_DUAL_EC_ALGORITHM, m_lengthByteArray);
		result2 = m_cryptRandomNumberGenerator.Generate(BCRYPT_RNG_DUAL_EC_ALGORITHM, m_lengthByteArray);
		ASSERT_NE(result1, result2);
	}
	timer.Stop();
}