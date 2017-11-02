#pragma once
#include "global.h"
class CScene;
class CObj;
class CSceneMgr
{
	SINGLE(CSceneMgr);
private:
	CScene*	 m_pCurScene;
	CScene*	 m_arrScene[SCENE_END];
public:
	CScene* GetCurrentScene() { return m_pCurScene; }
	bool AddObject(OBJ_TYPE _eType, CObj* _pObj);
public:
	void init();
	void update();
	void render(HDC _dc);
};

