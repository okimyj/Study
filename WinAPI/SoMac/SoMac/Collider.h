#pragma once
#include "global.h"
class CObj;
class CCollider
{
	static WORD		g_wNextID;		// CCollider 클래스 내에서만 접근 가능한 멤버 전역 변수. Collider를 생성 할 때 마다 uniqueid를 부여하기 위해 사용한다. 
													//	멤버 함수 안에서의 this는 클래스를 객체화해서 해당 함수를 호출한 객체 자신을 의미한다. static 키워드가 붙은 멤버 변수는 앞에 this가 당연히 없는거지. 

private:
	WORD					m_wID;
	CObj*					m_pOwner;
	COLLIDER_TYPE		m_eType;
	tPoint					m_ptSize;
	tPoint					m_ptOffset;			// owner의 pos로 부터 상대적 위치.
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

