#pragma once
#include "global.h"
class CTimeMgr
{
	SINGLE(CTimeMgr)
		
private:
	LARGE_INTEGER	m_llFrequency;			// 초당 진동 횟수.
	LARGE_INTEGER	m_llCurCnt;				// 현재 진동 횟수
	LARGE_INTEGER	m_llOldCnt;				// 이전 진동 횟수
	float						m_fDeltaTime;			// 한 프레임당 소요시간.	
	float						m_fAccTime;				// 누적 시간.

public:
	void init();
	void update();

public :
	float DeltaTime() { return m_fDeltaTime; }
};

