#pragma once
#include "global.h"
class CObj;
class CCollider
{
	static WORD		g_wNextID;		// CCollider Ŭ���� �������� ���� ������ ��� ���� ����. Collider�� ���� �� �� ���� uniqueid�� �ο��ϱ� ���� ����Ѵ�. 
													//	��� �Լ� �ȿ����� this�� Ŭ������ ��üȭ�ؼ� �ش� �Լ��� ȣ���� ��ü �ڽ��� �ǹ��Ѵ�. static Ű���尡 ���� ��� ������ �տ� this�� �翬�� ���°���. 

private:
	WORD					m_wID;
	CObj*					m_pOwner;
	COLLIDER_TYPE		m_eType;
	tPoint					m_ptSize;
	tPoint					m_ptOffset;			// owner�� pos�� ���� ����� ��ġ.
	COLORREF				m_color;
	bool						m_bCollision;


public:
	COLLIDER_TYPE GetColliderType() { return m_eType; }
	void SetColliderType(COLLIDER_TYPE _eType) { m_eType = _eType; }
	WORD GetID() { return m_wID; }
	CObj* GetColliderOwner() { return m_pOwner; }
	tPoint GetColliderSize() { return m_ptSize; }
	tPoint GetColliderPos();
	
public:
	void render(HDC _dc);

public:
	void OnCollisionEnter(CCollider * _pOther);
	void OnCollision(CCollider * _pOther);
	void OnCollisionExit(CCollider * _pOther);
	
public:
	CCollider(CObj* _pObj);
	CCollider(CObj* _pObj, COLLIDER_TYPE _eType, tPoint _ptSize, tPoint _ptOffset);
	~CCollider();
};

