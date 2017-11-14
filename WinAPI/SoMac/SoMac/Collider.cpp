#include "stdafx.h"
#include "Collider.h"
#include "Camera.h"
#include "Obj.h"
// static 변수 초기화. 
WORD CCollider::g_wNextID = 0;


CCollider::CCollider(CObj * _pObj)
	: m_wID(g_wNextID++)
	, m_pOwner(_pObj)
	, m_eType(COLLIDER_TYPE::COL_END)
	, m_ptSize{ 0.f, 0.f }
	, m_ptOffset{ 0.f, 0.f }
	, m_bCollision(false)
{
}

CCollider::CCollider(CObj * _pObj, COLLIDER_TYPE _eType, tPoint _ptSize, tPoint _ptOffset)
	: m_wID(g_wNextID++)
	, m_pOwner(_pObj)
	, m_eType(_eType)
	, m_ptSize(_ptSize)
	, m_ptOffset(_ptOffset)
	, m_bCollision(false)
{
}

CCollider::~CCollider()
{
}


tPoint CCollider::GetColliderPos()
{
	return m_pOwner->GetPos() + m_ptOffset;
}

void CCollider::render(HDC _dc)
{
	tPoint myPos = CCamera::GetInst()->GetWorldToScreenPosition(GetColliderPos());
	HPEN oldPen = (HPEN)SelectObject(_dc, GetStockObject(DC_PEN));

	if (m_bCollision)
		SetDCPenColor(_dc, RGB(255, 0, 0));
	else
		SetDCPenColor(_dc, RGB(0, 255, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(_dc, GetStockObject(HOLLOW_BRUSH));

	if (COL_CIRCLE == m_eType)
	{
		Ellipse(_dc, (int)myPos.x - m_ptSize.x / 2, (int)myPos.y - m_ptSize.y / 2
			, (int)myPos.x + m_ptSize.x / 2, (int)myPos.y + m_ptSize.y / 2);
	}
	else if (COL_RECT == m_eType)
	{
		Rectangle(_dc, (int)myPos.x - m_ptSize.x / 2, (int)myPos.y - m_ptSize.y / 2
			, (int)myPos.x + m_ptSize.x / 2, (int)myPos.y + m_ptSize.y / 2);
	}

	SelectObject(_dc, oldPen);
	SelectObject(_dc, oldBrush);
}


void CCollider::OnCollisionEnter(CCollider * _pOther)
{
	m_bCollision = true;
	m_pOwner->OnCollisionEnter(_pOther);
}

void CCollider::OnCollision(CCollider * _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void CCollider::OnCollisionExit(CCollider * _pOther)
{
	m_bCollision = false;
	m_pOwner->OnCollisionExit(_pOther);
}
