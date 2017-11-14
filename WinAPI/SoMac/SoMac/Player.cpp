#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Camera.h"
#include "GuideBullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Texture.h"


CPlayer::CPlayer()
	: m_fSpeed(250.f)
{
}


CPlayer::~CPlayer()
{
	SAFE_DEL(m_pTexRight);
	SAFE_DEL(m_pTexLeft)
	
}

void CPlayer::init()
{
	
	SetTag(L"Player");
	// Collider 생성 
	m_pCollider = new CCollider(this, COLLIDER_TYPE::COL_RECT, m_ptSize, tPoint{ 0.f, 0.f });
	// resource load .
	m_pTexRight = CResMgr::GetInst()->LoadTexture(L"Player\\player_right.bmp", L"PLAYER_RIGHT");
	m_pTexLeft = CResMgr::GetInst()->LoadTexture(L"Player\\player_left.bmp", L"PLAYER_LEFT");
	

	// Animator 생성
	m_pAnimator = new CAnimator(this);
	m_pAnimator->AddAnimation(L"RIGHT_IDLE", m_pTexRight, tPoint{ 0,0 }, 1, tPoint{ 64,70 }, tPoint{ 8,2}, 0.05f);
	m_pAnimator->AddAnimation(L"RIGHT_WALK", m_pTexRight, tPoint{ 0,140 }, 1, tPoint{ 64,70 }, tPoint{ 10,2 }, 0.05f);
	
	m_pAnimator->AddAnimation(L"LEFT_IDLE", m_pTexLeft, tPoint{ 1024, 0 }, -1, tPoint{ 64,70 }, tPoint{ 8,2 }, 0.05f);
	m_pAnimator->AddAnimation(L"LEFT_WALK", m_pTexLeft, tPoint{ 1024, 140 }, -1, tPoint{ 64,70 }, tPoint{ 10,2 }, 0.05f);

	m_pAnimator->PlayAnimation(L"LEFT_WALK");
}

void CPlayer::update()
{
	Move();
	AnimCheck();
	// 미사일 쏘기. 
	if (KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::DOWN))
		ShootBullet(false);
	if (KEY(KEY_TYPE::KEY_RBUTTON, KEY_STATE::DOWN))
		ShootBullet(true);
}

void CPlayer::Move()
{
	float fDT = CTimeMgr::GetInst()->DeltaTime();
	// 이동.
	if (KEY(KEY_TYPE::KEY_LEFT, KEY_STATE::HOLD))
	{
		m_ptPos.x -= m_fSpeed * fDT;
		m_iDir = -1;
		m_ePS = PLAYER_STATE::WALK;
	}
	else if (KEY(KEY_TYPE::KEY_RIGHT, KEY_STATE::HOLD))
	{
		m_ptPos.x += m_fSpeed * fDT;
		m_iDir = 1;
		m_ePS = PLAYER_STATE::WALK;
	}
	else
		m_ePS = PLAYER_STATE::IDLE;
	/*
	if (KEY(KEY_TYPE::KEY_UP, KEY_STATE::HOLD))
		m_ptPos.y -= m_fSpeed * fDT;
	if (KEY(KEY_TYPE::KEY_DOWN, KEY_STATE::HOLD))
		m_ptPos.y += m_fSpeed * fDT;
		*/
}

void CPlayer::AnimCheck()
{
	switch (m_ePS)
	{
	case PLAYER_STATE::IDLE:
		if (m_iDir > 0)
			m_pAnimator->PlayAnimation(L"RIGHT_IDLE");
		else
			m_pAnimator->PlayAnimation(L"LEFT_IDLE");
		break;
	case PLAYER_STATE::WALK:
		if (m_iDir > 0)
			m_pAnimator->PlayAnimation(L"RIGHT_WALK");
		else
			m_pAnimator->PlayAnimation(L"LEFT_WALK");
		break;	
	case PLAYER_STATE::END:
		break;
	default:
		break;
	}
}

void CPlayer::render(HDC _dc)
{
	if(NULL != m_pAnimator)
		m_pAnimator->render(_dc);
	if (NULL != m_pCollider)
		m_pCollider->render(_dc);
}

void CPlayer::ShootBullet(bool _bTargetting)
{
	CBullet* pBullet;
	// 마우스 클릭 방향.
	tPoint ptMouse = CKeyMgr::GetInst()->GetMousePos();
	float theta = RADIAN(ptMouse, m_ptPos);
	if (ptMouse.y > m_ptPos.y)
		theta = M_PI * 2 - theta;
	if (_bTargetting)
	{
		// TODO : 유도탄.
		CObj* target = CSceneMgr::GetInst()->GetCurrentScene()->FindNearTarget(OBJ_MONSTER, ptMouse);
		if (NULL != target)
		{
			if (NULL == m_pGuideBullet)
			{
				m_pGuideBullet = new CGuideBullet;
				CSceneMgr::GetInst()->AddObject(OBJ_PLAYER_BULLET, m_pGuideBullet);
			}
			m_pGuideBullet->SetPos(m_ptPos);
			m_pGuideBullet->SetSize(m_ptSize / 2);
			m_pGuideBullet->init();
			m_pGuideBullet->SetFollowTarget(target, theta);
			pBullet = m_pGuideBullet;
			CCamera::GetInst()->SetFollowTarget(m_pGuideBullet);
		}
		else
			return;
	}
	else
	{
		pBullet = new CBullet;
		pBullet->SetPos(m_ptPos);
		pBullet->SetSize(m_ptSize / 2);
		pBullet->init();
		CSceneMgr::GetInst()->AddObject(OBJ_PLAYER_BULLET, pBullet);
		pBullet->SetRad(theta);
	}
	
	//	float fSlash = DISTANCE(ptMouse, m_ptPos); // sqrt(pow(ptMouse.x - m_ptPos.x, 2) + pow(ptMouse.y - m_ptPos.y, 2));
	// float theta = acos((ptMouse.x - m_ptPos.x) / fSlash);
	
	
	
	// TODO : 마우스로 구한 theta랑 target과의 위치에서 구한 theta가 차이가 별로 없다면 최소 값을 지정해주자. 
	
}

void CPlayer::OnCollisionEnter(CCollider * _pOther)
{
}

void CPlayer::OnCollision(CCollider * _pOther)
{
}

void CPlayer::OnCollisionExit(CCollider * _pOther)
{
}
