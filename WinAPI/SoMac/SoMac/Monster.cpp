#include "stdafx.h"
#include "Monster.h"
#include "Collider.h"
#include "Camera.h"
CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}


void CMonster::init()
{
	// Collider ���� 
	m_pCollider = new CCollider(this, COLLIDER_TYPE::COL_RECT, m_ptSize, tPoint{ 0.f, 0.f });
	SetTag(L"Monster");
}

void CMonster::update()
{
}

void CMonster::render(HDC _dc)
{

	// ī�޶� ���� ��ġ ���ϱ�.
	tPoint ptCamPos = CCamera::GetInst()->GetInst()->GetWorldToScreenPosition(m_ptPos);

	Rectangle(_dc, (int)ptCamPos.x - m_ptSize.x / 2, (int)ptCamPos.y - m_ptSize.y / 2, (int)ptCamPos.x + m_ptSize.x / 2, (int)ptCamPos.y + m_ptSize.y / 2);

	if (NULL != m_pCollider)
		m_pCollider->render(_dc);


}

