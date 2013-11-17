#include "CryptRandomNumberGenerator.h"
#include "StringHelper.h"
#include <string>
#include <vector>

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

using namespace std;

CryptRandomNumberGenerator::CryptRandomNumberGenerator(void)
{
}


CryptRandomNumberGenerator::~CryptRandomNumberGenerator(void)
{
}

wstring CryptRandomNumberGenerator::Generate(const wstring & algType, int lengthRandomByteArray)
{
	BCRYPT_ALG_HANDLE hAlgorithm = NULL;
	StringHelper stringHelper;

	ULONG cbBuffer = lengthRandomByteArray;
	vector<UCHAR> pbBuffer;
	ULONG dwFlags = BCRYPT_RNG_USE_ENTROPY_IN_BUFFER;	
	wstring resultRandomString = L"";
	NTSTATUS status;

	status = BCryptOpenAlgorithmProvider(&hAlgorithm, algType.c_str(), NULL, 0);

	if(NT_SUCCESS(status))
	{
		pbBuffer.resize(cbBuffer);				

		status = BCryptGenRandom(hAlgorithm, &pbBuffer[0], cbBuffer, dwFlags);

		if (NT_SUCCESS(status))
		{
			status = BCryptCloseAlgorithmProvider(hAlgorithm, 0);
			if (NT_SUCCESS(status))
			{
				resultRandomString = stringHelper.ConvertByteArrayToString(&pbBuffer[0], cbBuffer);
			}
		}
	}

	return resultRandomString;
}