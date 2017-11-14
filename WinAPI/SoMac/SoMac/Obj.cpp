#include "stdafx.h"
#include "Obj.h"
#include "KeyMgr.h"
#include "Camera.h"
CObj::CObj()
	: m_ptPos{}
	, m_ptSize{}
	, m_pCollider(NULL)
	, m_pAnimator(NULL)
	, m_ptPivot{0.5f, 0.5f}
{
}


CObj::~CObj()
{
	SAFE_DEL(m_pCollider);
	SAFE_DEL(m_pAnimator);
}

bool CObj::CheckPointerOn(bool _bAbsolute)
{
	tPoint ptMouse = CKeyMgr::GetInst()->GetMousePos();
	if (!_bAbsolute)
		ptMouse = CCamera::GetInst()->GetScreenToWorldPosition(ptMouse);

	if ((m_ptPos.x - m_ptSize.x * m_ptPivot.x) < ptMouse.x && ptMouse.x <= (m_ptPos.x + m_ptSize.x * m_ptPivot.x)
		&& (m_ptPos.y - m_ptSize.y * m_ptPivot.y) < ptMouse.y && ptMouse.y <= (m_ptPos.y + m_ptSize.y * m_ptPivot.y))
		m_bPointerOn = true;
	else
		m_bPointerOn = false;
	return m_bPointerOn;
}

