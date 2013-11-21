// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>

#pragma warning (disable:4100)

#include <stdlib.h>
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

/* Memory block identification */
//#define _FREE_BLOCK      0
//#define _NORMAL_BLOCK    1
//#define _CRT_BLOCK       2
//#define _IGNORE_BLOCK    3
//#define _CLIENT_BLOCK    4
//#define _MAX_BLOCKS      5

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  
//
