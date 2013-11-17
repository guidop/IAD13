#pragma once
#include <Windows.h>
#include <string>
#include "IAD13ExportApi.h"

class IAD13_EXPORTS_API StringHelper
{
public:
	StringHelper(void);
	~StringHelper(void);
public:
	std::wstring ConvertByteArrayToString(const PUCHAR & byteArray, const int arrayLength);
};

