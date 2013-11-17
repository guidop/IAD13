#pragma once
#include <string>
#include "IAD13ExportApi.h"

class IAD13_EXPORTS_API CryptRandomNumberGenerator
{
public:
	CryptRandomNumberGenerator(void);
	~CryptRandomNumberGenerator(void);

public:
	std::wstring Generate(const std::wstring & algType, int lengthRandomByteArray);
};