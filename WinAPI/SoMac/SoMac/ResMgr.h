#pragma once
#include "global.h"
class CTexture;
class CResMgr
{
	SINGLE(CResMgr);
private:
	map<wstring, CTexture*>		m_mapTexture;
public:
	CTexture* LoadTexture(const wstring& _strPath, const wstring& _strKey);
	CTexture* GetTexture(const wstring& _strKey);
	void Clear();
};

