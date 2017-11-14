#include "stdafx.h"
#include "PathMgr.h"
// static 변수 초기화.
wchar_t CPathMgr::m_szResPath[255] = {};
CPathMgr::CPathMgr()
{
}


CPathMgr::~CPathMgr()
{
}

void CPathMgr::init()
{
	// Resource 폴더까지의 절대 경로 구하기. 
	GetCurrentDirectory(255, m_szResPath);
	int iLen = wcslen(m_szResPath);
	for (int i = iLen - 1; i > 0; --i)
	{
		if (m_szResPath[i] == '\\')
		{
			wmemset(m_szResPath + i, 0, iLen - i);
			break;
		}
	}
	wcscat_s(m_szResPath, 255, L"\\Bin\\Resources\\");
}
