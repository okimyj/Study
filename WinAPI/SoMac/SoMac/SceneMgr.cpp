#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneLogo.h"
#include "SceneReady.h"
#include "SceneGame.h"
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
	m_arrScene[SCENE_LOGO] = new CSceneLogo();
	m_arrScene[SCENE_READY] = new CSceneReady();
	m_arrScene[SCENE_GAME] = new CSceneGame();

	ChangeScene(SCENE_LOGO);
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

bool CSceneMgr::ChangeScene(SCENE_TYPE _eType)
{
	if (NULL != m_arrScene[_eType])
	{
		if(NULL != m_pCurScene)
			m_pCurScene->exit();

		m_pCurScene = m_arrScene[_eType];
		m_pCurScene->enter();
	}

	return false;
}

