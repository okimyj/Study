#pragma once
#include "global.h"
class CPathMgr
{
private:
	CPathMgr();
	~CPathMgr();
private:
	static wchar_t m_szResPath[255];
public:
	static void init();
	static wchar_t* GetResPath() { return m_szResPath; }
};

