#include "MemoryLeakListener.h"
#include <Windows.h>

CMemoryLeakListener::CMemoryLeakListener()
{
	m_hookPrinter = IsDebuggerPresent() == 0;
}

void CMemoryLeakListener::OnTestStart(const ::testing::TestInfo& )
{
	_CrtMemCheckpoint( &memAtStart );
}

void CMemoryLeakListener::OnTestEnd(const ::testing::TestInfo& test_info)
{
	if(test_info.result()->Passed())
	{
		CheckForMemLeaks(test_info); 
	}
}

void CMemoryLeakListener::CheckForMemLeaks(const ::testing::TestInfo& test_info)
{
    _CrtMemState memAtEnd;memAtEnd;
    _CrtMemCheckpoint( &memAtEnd );
    _CrtMemState memDiff;memDiff;

	int ret = _CrtMemDifference(&memDiff, &memAtStart, &memAtEnd);
    if (ret)
	{
        _CrtMemDumpStatistics( &memDiff );
		_CrtMemDumpAllObjectsSince(&memAtStart);
        FAIL() << "Memory leak in " << test_info.test_case_name() << "." << test_info.name() << '\n';
	}
}

int __cdecl printToStdErr(int , char* szMsg, int* ){
 std::cerr << szMsg; 
 return 1; // No further processing required by _CrtDebugReport
}

void CMemoryLeakListener::OnTestProgramStart(const ::testing::UnitTest& )
{
	if (m_hookPrinter)
		_CrtSetReportHook2(_CRT_RPTHOOK_INSTALL, &printToStdErr);
}
void CMemoryLeakListener::OnTestProgramEnd(const ::testing::UnitTest& )
{
	if (m_hookPrinter)
		_CrtSetReportHook2(_CRT_RPTHOOK_REMOVE, &printToStdErr);
}