#pragma once
#include "global.h"
class CObj;
class CScene
{
protected:
	vector<CObj*>		m_vecObj[OBJ_END];
public:
	virtual void enter() = 0;
	virtual void exit() = 0;
	virtual void update() = 0;
	virtual void render(HDC _dc);
	bool AddObject(OBJ_TYPE _eType, CObj* _pObj);
	vector<CObj*> GetObjVector(OBJ_TYPE _eType) { return m_vecObj[_eType]; }
	CObj* FindNearTarget(OBJ_TYPE _eType, tPoint _ptPos);
public:
	CScene();
	virtual ~CScene();
};

