#pragma once
#include "global.h"
class CObj;
class CCamera
{
	SINGLE(CCamera);

private:
	tPoint		m_ptCenter;					// ó�� ī�޶� �ٶ󺸰� �ִ� �߽� ��ġ. 
	tPoint		m_ptOriginCenter;			// target�� �Ѿư��ٰ� �ٽ� ���ƿ��� ���ؼ�..
	tPoint		m_ptOffset;					// ó�� ��ġ���� ����Ʈ���� ������ ũ��.
	tPoint		m_ptDiff;						// ������ ���� 0������ �󸶳� �̵��� �ִ���. 
	CObj*		m_pFollowTarget;			// �Ѿƴٴ� Ÿ�� obj. 


	bool			m_bVib;						// ī�޶� ���� ����.
	float			m_fVibTime;					//	���� �� �ð�. 
	float			m_fVibAccTime;				// ���� ���� �ð�.
	tPoint		m_ptVibRange;					// ���� ����.
	float			m_fVibSpeed;				// ���� �ӵ�.

public:
	void init(tPoint _ptCenter, CObj*	_pFollowTarget);
	void update();

public:
	tPoint GetScreenToWorldPosition(tPoint _ptPos);					// ī�޶� ���� position �� ���� position���� ��ȯ.
	tPoint GetWorldToScreenPosition(tPoint _ptPos);					// ���� position�� ī�޶� �������� ��ȯ.
	void SetVibration(float _fTime, tPoint _ptRange, float _fSpeed = 2000.f);
	void SetFollowTarget(CObj* _pTarget);
private:
	void MoveCamera();
	void CalcOffset();

};

