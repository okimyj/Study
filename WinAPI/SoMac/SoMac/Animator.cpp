#include "stdafx.h"
#include "Animator.h"
#include "Animation.h"

CAnimator::CAnimator(CObj * _pOwner)
	: m_pOwner(_pOwner)
	, m_pCurAnim(NULL)
	, m_bPause(false)
{
}

CAnimator::~CAnimator()
{
	SAFE_DEL_MAP(wstring, CAnimation*, m_mapAnim);
}


void CAnimator::render(HDC _dc)
{
	if (m_bPause)
		return;
	if (NULL != m_pCurAnim)
		m_pCurAnim->render(_dc, m_pOwner);
}

void CAnimator::AddAnimation(const wstring & _strKey, CTexture * _pTexture, tPoint _ptStart, int _iDir, tPoint _ptCropSize, tPoint mapSize, float _fInterval)
{
	CAnimation* pAnim = new CAnimation;
	for (int i = 0; i < mapSize.y; ++i)
	{
		for (int j = 0; j < mapSize.x; ++j)
		{
			tFrame frame = {};
			frame.m_pTexture = _pTexture;
			frame.m_ptStartPos.x = _ptStart.x + _iDir * (j * _ptCropSize.x);
			frame.m_ptStartPos.y = _ptStart.y + (i * _ptCropSize.y);
			frame.m_iDir = _iDir;
			frame.m_ptCropSize = _ptCropSize;
			frame.m_fInteval = _fInterval;
			pAnim->AddFrame(frame);
		}
	}
	/*
	for (int i = 0; i < _iMaxFrame; ++i)
	{
		tFrame frame = {};
		frame.m_pTexture = _pTexture;
		frame.m_ptStartPos.x = _ptStart.x + _iDir * (i * _ptCropSize.x);
		frame.m_ptStartPos.y = _ptStart.y;
		frame.m_iDir = _iDir;
		frame.m_ptCropSize = _ptCropSize;
		frame.m_fInteval = _fInterval;
		pAnim->AddFrame(frame);
	}
	*/
	m_mapAnim.insert(make_pair(_strKey, pAnim));
}

void CAnimator::PlayAnimation(const wstring & _strKey, bool _bLoop)
{
	map<wstring, CAnimation*>::iterator iter = m_mapAnim.find(_strKey);
	if (iter == m_mapAnim.end())
		assert(NULL);
	
	m_pCurAnim = iter->second;
	m_pCurAnim->Reset(_bLoop);
}

void CAnimator::PauseAnimation(bool _bPause)
{
	m_bPause = _bPause;
}

void CAnimator::StopAnimation()
{
	if (NULL != m_pCurAnim)
	{
		m_pCurAnim->Reset();
		m_pCurAnim = NULL;
	}
}

