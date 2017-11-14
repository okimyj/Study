#pragma once
#include "Bullet.h"

class CGuideBullet :
	public CBullet
{
private:
	CObj*		m_pTarget;



public :
	virtual void update();
	void SetFollowTarget(CObj* _pTarget, float _fInitRad);
	

public:
	CGuideBullet();
	virtual ~CGuideBullet();
};

