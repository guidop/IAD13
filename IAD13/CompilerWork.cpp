#include "CompilerWork.h"
#include <stdio.h>
#include <direct.h>

CompilerWork::CompilerWork()
{
}


CompilerWork::~CompilerWork()
{
}

_Check_return_ bool func()
{
	return true;
}

_Check_return_ int func_range(_In_range_(1, 3) int val)
{
	return val * 2;
}

class P
{
public:
	int a;
	int b;
};

void f()
{
	//func(); //  Warning C6031
	//int *p = new int[10];
	//delete p; //  Warning C6283

	//P *p = nullptr;	
	//p->a = 1;  Warning C6011

	//{
	//	int aa;
	//	aa = 1; aa;

	//	{
	//		int aa;  Warning C6246
	//		aa = 2; aa;
	//	}
	//}
	//int aa; int val=4;
	//if (func_range(val) > 1)
	//	aa = 1;
}

