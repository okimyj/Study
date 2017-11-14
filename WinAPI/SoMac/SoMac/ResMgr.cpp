#include "stdafx.h"
#include "ResMgr.h"
#include "PathMgr.h"
#include "Texture.h"
CResMgr::CResMgr(){}

CResMgr::~CResMgr()
{
	Clear();
}

CTexture * CResMgr::LoadTexture(const wstring & _strPath, const wstring & _strKey)
{
	wstring strPath = CPathMgr::GetResPath() + _strPath;
	CTexture* pTextrue = NULL;
	map<wstring, CTexture*>::iterator iter = m_mapTexture.find(_strKey);
	if (iter != m_mapTexture.end())
		pTextrue = iter->second;
	else
	{
		pTextrue = CTexture::Load(strPath);
		if (NULL == pTextrue)
		{
			MessageBox(g_hWnd, L"알림", L"이미지 로드 실패.\n", MB_OK);
			return NULL;
		}
		m_mapTexture.insert(make_pair(_strKey, pTextrue));
	}
	return pTextrue;
}

CTexture * CResMgr::GetTexture(const wstring & _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTexture.find(_strKey);
	
	if (iter == m_mapTexture.end())
		return NULL;

	return iter->second;
}

void CResMgr::Clear()
{
	SAFE_DEL_MAP(wstring, CTexture*, m_mapTexture);
	m_mapTexture.clear();
}

