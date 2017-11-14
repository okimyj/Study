#pragma once
#include "global.h"
class CCollider;
class CAnimator;
class CObj
{
protected:
	wstring	m_strTag;
	tPoint	m_ptSize;
	tPoint	m_ptPos;
	tPoint	m_ptPivot;

	CAnimator*		m_pAnimator;
	CCollider*			m_pCollider;
	bool					m_bPointerOn;					// mouse pointer�� obj ���� ���� �ִ� ����.		
	
public :
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render(HDC _dc) = 0;

public:
	tPoint GetSize() { return m_ptSize; }
	void SetSize(tPoint _ptSize) { m_ptSize = _ptSize; }
	tPoint GetPos() { return m_ptPos; }
	void SetPos(tPoint _ptPos) { m_ptPos = _ptPos; }
	tPoint GetPivot() { return m_ptPivot; }
	void SetPivot(tPoint _ptPivot) { m_ptPivot = _ptPivot; }

	const wstring& GetTag() { return m_strTag; }
	void SetTag(const wstring& _strTag) { m_strTag = _strTag; }
	CCollider* GetCollider() { return m_pCollider; }
	bool HasCollider() { return NULL != m_pCollider; }

public:
	virtual void OnCollisionEnter(CCollider* _pCollider) {};
	virtual void OnCollision(CCollider* _pCollider) {};
	virtual void OnCollisionExit(CCollider* _pCollider) {};

public:
	bool CheckPointerOn(bool _bAbsolute);				// _bAbsolute == true : ī�޶� ������ �ƴ� ���� ��ġ�� check. 
	bool IsPointerOn() { return m_bPointerOn;}
public:
	CObj();
	virtual ~CObj();
};

