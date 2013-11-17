#pragma once
#include "IAD13ExportApi.h"

class IAD13_EXPORTS_API CTimer
{
public:
	CTimer(void);
	~CTimer(void);
public :
	void Start();
	void Stop();
	void GetElapsedTimeInMicros();
private:
	double m_TimeOccured;
	__int64 m_StartTime;
	__int64 m_StopTime;
	__int64 m_Frequency;
};

