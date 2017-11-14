#pragma once
#include "Scene.h"
class CSceneReady :
	public CScene
{
public:
	virtual void enter();
	virtual void exit();
	virtual void update();
	virtual void render(HDC _dc);
public:
	CSceneReady();
	virtual ~CSceneReady();
};

