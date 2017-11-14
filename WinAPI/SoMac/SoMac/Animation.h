#pragma once
#include "global.h"
class CTexture;
class CObj;
class CAnimation
{
private:
	vector<tFrame>		m_vecFrame;
	int				m_iCurFrame;			// ���� ������. 
	float			m_fAccTime;				// ���� �ð�. 
	bool			m_bLoop;
public:
	void Reset(bool _bLoop = true);
public:
	void render(HDC _dc, CObj* _pOwner);
public:
	void AddFrame(const tFrame& _frame) { m_vecFrame.push_back(_frame); }
public:
	CAnimation();
	~CAnimation();
};

