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
	// QueryPerformanceFrequency() : �ʴ� ���� Ƚ���� �����´�. �뷫 ��鸸�� ���� ��ȯ��. 
	// clock���� ��� �ϴ� GetTickCount �� CPU�� ��� �ϱ� ������ �ʴ� ��Ȯ�ϰ� 1000���� �ƴ� �� �ִ�.
	// ��� CPU��� ���ϰ� ������ üũ�ϴ°�. �ξ� �������̰� �̼��� ��Ʈ���� �����ϴ�.
	QueryPerformanceFrequency(&m_llFrequency);
	// QueryPerformanceCounter() : ȣ�� ���� ������ ���� Ƚ��. ��ǻ�͸� ������ �������� counting�Ѵ�.
	QueryPerformanceCounter(&m_llCurCnt);
	m_llOldCnt = m_llCurCnt;
}

void CTimeMgr::update()
{
	// ���� ���� Ƚ�� ����.
	QueryPerformanceCounter(&m_llCurCnt);
	// ���� ���������� ���� ���� ���� �� ���� �ʴ� ���� Ƚ���� ����� �� �����ӿ� �ҿ�� �ð��� ��´�.
	m_fDeltaTime = (m_llCurCnt.QuadPart - m_llOldCnt.QuadPart) / (float)m_llFrequency.QuadPart;
	m_llOldCnt = m_llCurCnt;

	// deltaTime�� �����ؼ� 1�ʿ� �ѹ��� frequency���� ���� ���ش�. �� �� ��Ȯ�ϰ� �ϱ� ���ؼ�.
	m_fAccTime += m_fDeltaTime;			// �ð� ����.
	if(m_fAccTime > 1.f)
	{
		m_fAccTime = 0.f;
		QueryPerformanceFrequency(&m_llFrequency);
	}
}
