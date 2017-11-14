#include "stdafx.h"
#include "Animation.h"
#include "Camera.h"
#include "Texture.h"
#include "Obj.h"
#include "TimeMgr.h"

CAnimation::CAnimation()
	: m_iCurFrame(0)
	, m_fAccTime(0.f)
{
}


CAnimation::~CAnimation()
{
}

void CAnimation::Reset(bool _bLoop)
{
	m_iCurFrame = 0;
	m_fAccTime = 0.f;
}

void CAnimation::render(HDC _dc, CObj * _pOwner)
{
	// 카메라 기준 위치 구하기
	
	tPoint ptCamPos = CCamera::GetInst()->GetWorldToScreenPosition(_pOwner->GetPos());
	tFrame& frame = m_vecFrame[m_iCurFrame];
	if (frame.m_iDir > 0)
	{
		TransparentBlt(_dc
			, ptCamPos.x - frame.m_ptCropSize.x / 2.f
			, ptCamPos.y - frame.m_ptCropSize.y / 2.f
			, frame.m_ptCropSize.x
			, frame.m_ptCropSize.y
			, frame.m_pTexture->GetDC()
			, frame.m_ptStartPos.x
			, frame.m_ptStartPos.y
			, frame.m_ptCropSize.x
			, frame.m_ptCropSize.y
			, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(_dc
			, ptCamPos.x - frame.m_ptCropSize.x / 2.f
			, ptCamPos.y - frame.m_ptCropSize.y / 2.f
			, frame.m_ptCropSize.x
			, frame.m_ptCropSize.y
			, frame.m_pTexture->GetDC()
			, frame.m_ptStartPos.x - frame.m_ptCropSize.x
			, frame.m_ptStartPos.y
			, frame.m_ptCropSize.x
			, frame.m_ptCropSize.y
			, RGB(255, 0, 255));
	}
	m_fAccTime += DT;
	float dt = DT;
	if (frame.m_fInteval < m_fAccTime)
	{
		m_fAccTime = 0.f;
		++m_iCurFrame;

		if (m_iCurFrame >= m_vecFrame.size())
			m_iCurFrame = 0;
	}
	
}
