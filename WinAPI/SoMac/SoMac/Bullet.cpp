#include "stdafx.h"
#include "Bullet.h"
#include "Collider.h"
#include "TimeMgr.h"
#include "Camera.h"

CBullet::CBullet()
	: m_fSpeed(500.f)
	, m_fRad(0.f)
{	
}


CBullet::~CBullet()
{
}


void CBullet::init()
{
	// collider 생성 
	if(NULL == m_pCollider)
		m_pCollider = new CCollider(this, COL_CIRCLE, m_ptSize, tPoint{ 0, 0 });
	m_strTag = L"Bullet";
}

void CBullet::update()
{
//	m_fRad += M_PI * DT;
	m_ptPos.x += m_fSpeed * DT * cosf(m_fRad);
	m_ptPos.y -= m_fSpeed * DT * sinf(m_fRad);
}

void CBullet::render(HDC _dc)
{
	// bullet 실제 위치를 카메라 기준 위치로 변경해서 그려준다..
	tPoint ptCamPos = CCamera::GetInst()->GetWorldToScreenPosition(m_ptPos);
	
	Ellipse(_dc, (int)ptCamPos.x - m_ptSize.x / 2, (int)ptCamPos.y - m_ptSize.y / 2
		, (int)ptCamPos.x + m_ptSize.x / 2, (int)ptCamPos.y + m_ptSize.y / 2);

	m_pCollider->render(_dc);
}