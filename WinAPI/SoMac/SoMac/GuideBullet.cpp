#include "stdafx.h"
#include "GuideBullet.h"
#include "TimeMgr.h"
CGuideBullet::CGuideBullet()
{
}


CGuideBullet::~CGuideBullet()
{
}

void CGuideBullet::update()
{
	// 맨 처음 CBullet 의 m_fRad 는 클릭 위치. 
	// 서서히 target으로의 각도로 바꿔주면 된다. 
	if (NULL != m_pTarget)
	{
		float fNewRad = RADIAN(m_pTarget->GetPos(), GetPos());
		
		if (m_pTarget->GetPos().y > m_ptPos.y)
			fNewRad = M_PI * 2 - fNewRad;

		if (m_fRad != fNewRad)
		{
			if(fNewRad > m_fRad)
				m_fRad = min(m_fRad + fNewRad * DT, fNewRad);
			else
				m_fRad = max(m_fRad - fNewRad * DT, fNewRad);
		}
		else
		{
			m_fRad = fNewRad;
		}
		CBullet::update();		
	}
}

void CGuideBullet::SetFollowTarget(CObj * _pTarget, float _fInitRad)
{
	m_pTarget = _pTarget;
	m_fRad = _fInitRad;
	/*
	float fNewRad = RADIAN(m_pTarget->GetPos(), GetPos());
	if (m_pTarget->GetPos().y > m_ptPos.y)
		fNewRad = M_PI * 2 - fNewRad;

	float what = (M_PI/6);
	if (abs(_fInitRad - fNewRad) < (M_PI/6))
	{
		m_fRad = _fInitRad * 1.5f;
	}
	else
		m_fRad = _fInitRad;
		*/
}
