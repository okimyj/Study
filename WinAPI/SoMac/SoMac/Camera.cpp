#include "stdafx.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Camera.h"
#include "Obj.h"


CCamera::CCamera()
	: m_ptCenter{ 0,0 }
	, m_pFollowTarget(NULL)
{
}


CCamera::~CCamera()
{
}

void CCamera::init(tPoint _ptCenter, CObj * _pFollowTarget)
{
	m_ptCenter = _ptCenter;
	m_pFollowTarget = _pFollowTarget;
}

void CCamera::update()
{
	MoveCamera();
	CalcOffset();
	if (NULL != m_pFollowTarget && m_ptCenter != m_pFollowTarget->GetPos())
	{
		m_ptCenter = m_pFollowTarget->GetPos();
		/*
		tPoint targetPos = m_pFollowTarget->GetPos();
		tPoint ptDiff = targetPos - m_ptOriginCenter;
		
		m_ptCenter += ptDiff * 0.1f;
		*/
	}
	// 화면 중심 점에서부터 카메라가 보는 중심점이 얼마나 떨어져 있는지.
	m_ptDiff.x = m_ptCenter.x + m_ptOffset.x - WINSIZE_X / 2.f;
	m_ptDiff.y = m_ptCenter.y + m_ptOffset.y - WINSIZE_Y / 2.f;
}

tPoint CCamera::GetScreenToWorldPosition(tPoint _ptPos)
{
	_ptPos.x += m_ptDiff.x;
	_ptPos.y += m_ptDiff.y;
	return tPoint(_ptPos);
}

tPoint CCamera::GetWorldToScreenPosition(tPoint _ptPos)
{
	_ptPos.x -= m_ptDiff.x;
	_ptPos.y -= m_ptDiff.y;
	return tPoint(_ptPos);
}

void CCamera::SetVibration(float _fTime, tPoint _ptRange, float _fSpeed)
{
	m_bVib = true;
	m_fVibTime = _fTime;
	m_ptVibRange = _ptRange;
	m_fVibSpeed = _fSpeed;
	m_fVibAccTime = 0;
}

void CCamera::SetFollowTarget(CObj * _pTarget)
{
	m_pFollowTarget = _pTarget;
	if (NULL != m_pFollowTarget)
		m_ptOriginCenter = m_ptCenter;
	
}

void CCamera::MoveCamera()
{
	if (KEY(KEY_TYPE::KEY_W, KEY_STATE::HOLD))
		m_ptCenter.y -= 200.f * DT;
	if (KEY(KEY_TYPE::KEY_S, KEY_STATE::HOLD))
		m_ptCenter.y += 200.f * DT;
	if (KEY(KEY_TYPE::KEY_A, KEY_STATE::HOLD))
		m_ptCenter.x -= 200.f * DT;
	if (KEY(KEY_TYPE::KEY_D, KEY_STATE::HOLD))
		m_ptCenter.x += 200.f * DT;
}

void CCamera::CalcOffset()
{
	if (!m_bVib)
	{
		m_ptOffset = tPoint{ 0.f, 0.f };
		return;
	}
	// 카메라 진동이 켜져 있다면.

	static int iDir = -1;
	m_ptOffset.y -= DT * m_fVibSpeed * iDir;
	if (abs(m_ptOffset.y) > m_ptVibRange.y)
	{
		m_ptVibRange.y = iDir * m_ptVibRange.y;
		iDir *= -1;
	}

	m_fVibAccTime += DT;
	if (m_fVibAccTime >= m_fVibTime)
	{
		m_bVib = false;
	}
}
