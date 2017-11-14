#pragma once
#include "global.h"
class CTimeMgr
{
	SINGLE(CTimeMgr)
		
private:
	LARGE_INTEGER	m_llFrequency;			// �ʴ� ���� Ƚ��.
	LARGE_INTEGER	m_llCurCnt;				// ���� ���� Ƚ��
	LARGE_INTEGER	m_llOldCnt;				// ���� ���� Ƚ��
	float						m_fDeltaTime;			// �� �����Ӵ� �ҿ�ð�.	
	float						m_fAccTime;				// ���� �ð�.

public:
	void init();
	void update();

public :
	float DeltaTime() { return m_fDeltaTime; }
};

