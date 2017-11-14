#pragma once
#include "Obj.h"
class CGuideBullet;
class CAnimator;
class CPlayer :
	public CObj
{
private:
	float							m_fSpeed;					// �̵��ӵ�.
	CGuideBullet*			m_pGuideBullet;
	CTexture*					m_pTexRight;
	CTexture*					m_pTexLeft;
	int								m_iDir;		// player ����. 1: right -1 : left
	PLAYER_STATE			m_ePS;		// player state. animation ���� �ϰ� ���߿� ���� ���... 

public:
	virtual void init();
	virtual void update();
	virtual void render(HDC _dc);

private:
	void ShootBullet(bool _bTargetting);
	void Move();
	void AnimCheck();

public:
	virtual void OnCollisionEnter(CCollider * _pOther);
	virtual void OnCollision(CCollider * _pOther);
	virtual void OnCollisionExit(CCollider * _pOther);
public:
	CPlayer();
	virtual ~CPlayer();
};

