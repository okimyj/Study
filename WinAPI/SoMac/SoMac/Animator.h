#pragma once
#include "global.h"

class CAnimation;
class CObj;
class CAnimator
{
private:
	CObj*		m_pOwner;
	map<wstring, CAnimation*>		m_mapAnim;
	CAnimation*		m_pCurAnim;
	bool					m_bPause;
public:
	void render(HDC _dc);
public:
	void AddAnimation(const wstring& _strKey, CTexture* _pText, tPoint _ptStart, int _iDir, tPoint _ptCropSize, tPoint mapSize, float _fInterval);
	void PlayAnimation(const wstring& _strKey, bool _bLoop = true);
	void PauseAnimation(bool _bPause);
	void StopAnimation();
public:
	CAnimator(CObj* _pOwner);
	~CAnimator();
};

