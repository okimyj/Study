#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene.h"
CSceneMgr::CSceneMgr()
	: m_pCurScene(NULL)
	, m_arrScene{}
{
}

CSceneMgr::~CSceneMgr()
{
	for (int i = 0; i < SCENE_END; ++i)
	{
		SAFE_DEL(m_arrScene[i]);
	}
}

void CSceneMgr::init()
{
	
}

void CSceneMgr::update()
{
	m_pCurScene->update();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}


bool CSceneMgr::AddObject(OBJ_TYPE _eType, CObj * _pObj)
{
	m_pCurScene->AddObject(_eType, _pObj);
	return false;
}

