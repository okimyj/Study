#pragma once
#include "global.h"
class CObj;
class CScene
{
private:
	vector<CObj*>		m_vecObj[OBJ_END];
public:
	virtual void update() = 0;
	virtual void render(HDC _dc) = 0;
	bool AddObject(OBJ_TYPE _eType, CObj* _pObj);
public:
	CScene();
	virtual ~CScene();
};

