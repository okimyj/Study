#include "stdafx.h"
#include "TimeMgr.h"


CTimeMgr::CTimeMgr()
	: m_llFrequency{0}
	, m_llCurCnt{0}
	, m_llOldCnt{0}
	, m_fDeltaTime(0)
	, m_fAccTime(0)
{}
CTimeMgr::~CTimeMgr(){}

void CTimeMgr::init()
{
	// QueryPerformanceFrequency() : 초당 진동 횟수를 가져온다. 대략 몇백만의 값을 반환함. 
	// clock에서 사용 하는 GetTickCount 는 CPU를 사용 하기 때문에 초당 정확하게 1000번이 아닐 수 있다.
	// 얘는 CPU사용 안하고 진동만 체크하는거. 훨씬 안정적이고 미세한 컨트롤이 가능하다.
	QueryPerformanceFrequency(&m_llFrequency);
	// QueryPerformanceCounter() : 호출 시점 까지의 진동 횟수. 컴퓨터를 부팅한 순간부터 counting한다.
	QueryPerformanceCounter(&m_llCurCnt);
	m_llOldCnt = m_llCurCnt;
}

void CTimeMgr::update()
{
	// 현재 진동 횟수 갱신.
	QueryPerformanceCounter(&m_llCurCnt);
	// 현재 진동값에서 이전 진동 값을 뺀 값을 초당 진동 횟수로 나누어서 한 프레임에 소요된 시간을 얻는다.
	m_fDeltaTime = (m_llCurCnt.QuadPart - m_llOldCnt.QuadPart) / (float)m_llFrequency.QuadPart;
	m_llOldCnt = m_llCurCnt;

	// deltaTime을 누적해서 1초에 한번씩 frequency값을 갱신 해준다. 좀 더 정확하게 하기 위해서.
	m_fAccTime += m_fDeltaTime;			// 시간 누적.
	if(m_fAccTime > 1.f)
	{
		m_fAccTime = 0.f;
		QueryPerformanceFrequency(&m_llFrequency);
	}
}
