#include <tchar.h>
#include "gtest\gtest.h"
#include "MemoryLeakListener.h"

using namespace std;

void bye(void)
{
	puts("Goodbye, cruel world....");
}

int _tmain(int argc, _TCHAR* argv[])
{
	atexit(bye);

	::testing::InitGoogleTest(&argc, argv);
	
	auto &listeners = ::testing::UnitTest::GetInstance()->listeners();

	
	std::wstring command_line_arg(argc == 2 ? argv[1] : L"");
	bool hookPrinter = (command_line_arg.compare(L"1") == 0); 
	
	listeners.Append(new CMemoryLeakListener(hookPrinter));

	return RUN_ALL_TESTS();
}
