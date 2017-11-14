#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	virtual void init();
	virtual void update();
	virtual void render(HDC _dc);

public:
	CMonster();
	virtual ~CMonster();
};

