#pragma once
#include "Scene.h"
class CSceneGame
	: public CScene
{
public:
	virtual void enter();
	virtual void exit();
	virtual void update();
	virtual void render(HDC _dc);
public:
	CSceneGame();
	virtual ~CSceneGame();
};

