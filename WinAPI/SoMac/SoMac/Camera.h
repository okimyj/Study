#pragma once
#include "global.h"
class CObj;
class CCamera
{
	SINGLE(CCamera);

private:
	tPoint		m_ptCenter;					// 처음 카메라가 바라보고 있는 중심 위치. 
	tPoint		m_ptOriginCenter;			// target을 쫓아갔다가 다시 돌아오기 위해서..
	tPoint		m_ptOffset;					// 처음 위치에서 떨어트려서 보여줄 크기.
	tPoint		m_ptDiff;						// 윈도우 기준 0점에서 얼마나 이동해 있는지. 
	CObj*		m_pFollowTarget;			// 쫓아다닐 타겟 obj. 


	bool			m_bVib;						// 카메라 진동 상태.
	float			m_fVibTime;					//	진동 할 시간. 
	float			m_fVibAccTime;				// 진동 누적 시간.
	tPoint		m_ptVibRange;					// 진동 범위.
	float			m_fVibSpeed;				// 진동 속도.

public:
	void init(tPoint _ptCenter, CObj*	_pFollowTarget);
	void update();

public:
	tPoint GetScreenToWorldPosition(tPoint _ptPos);					// 카메라 기준 position 을 실제 position으로 변환.
	tPoint GetWorldToScreenPosition(tPoint _ptPos);					// 실제 position을 카메라 기준으로 변환.
	void SetVibration(float _fTime, tPoint _ptRange, float _fSpeed = 2000.f);
	void SetFollowTarget(CObj* _pTarget);
private:
	void MoveCamera();
	void CalcOffset();

};

