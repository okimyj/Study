#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
protected:
	float	m_fSpeed;
	float   m_fRad;
public:
	virtual void init();
	virtual void update();
	virtual void render(HDC _dc);

public:
	void SetRad(float _fRad) { m_fRad = _fRad; }

public:
	CBullet();
	virtual ~CBullet();
};

