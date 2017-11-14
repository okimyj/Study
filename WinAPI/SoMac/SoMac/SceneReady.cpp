#include "stdafx.h"
#include "SceneReady.h"
#include "SceneMgr.h"

void CSceneReady::enter()
{
	CSceneMgr::GetInst()->ChangeScene(SCENE_GAME);
}

void CSceneReady::exit()
{
}

void CSceneReady::update()
{
}

void CSceneReady::render(HDC _dc)
{
}

CSceneReady::CSceneReady()
{
}


CSceneReady::~CSceneReady()
{
}
