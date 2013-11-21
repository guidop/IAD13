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

	listeners.Append(new CMemoryLeakListener{});

	return RUN_ALL_TESTS();
}
