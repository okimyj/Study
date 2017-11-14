#include "stdafx.h"
#include "SceneLogo.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Texture.h"
#include "Camera.h"
#include "UIButton.h"

void CSceneLogo::enter()
{
	m_pBackground = CResMgr::GetInst()->LoadTexture(L"logo.bmp", L"LOGO");
	CCamera::GetInst()->init(tPoint{ WINSIZE_X / 2, WINSIZE_Y / 2 }, NULL);
	// Create Start button.
	CTexture* pTexStartBtnNormal = CResMgr::GetInst()->LoadTexture(L"UI\\button_start_normal.bmp", L"START_BTN_NORMAL");
	CTexture* pTexStartBtnEnter = CResMgr::GetInst()->LoadTexture(L"UI\\button_start_enter.bmp", L"START_BTN_ENTER");
	CTexture* pTexStartBtnDown = CResMgr::GetInst()->LoadTexture(L"UI\\button_start_down.bmp", L"START_BTN_DOWN");
	CUIButton* startButton = new CUIButton(pTexStartBtnNormal, pTexStartBtnEnter, pTexStartBtnDown);
	startButton->SetPivot(tPoint{ 0.5f, 0.5f });
	startButton->SetPos(tPoint{ WINSIZE_X / 2, WINSIZE_Y / 2 });
	
	startButton->SetSize(tPoint{ pTexStartBtnNormal->GetWidth(), pTexStartBtnNormal->GetHeight() });
	//startButton->m_pClickCallback += this->ClickStartButton;
	m_vecObj[OBJ_UI].push_back(startButton);
}



void CSceneLogo::exit()
{
}

void CSceneLogo::update()
{
	if (KEY(KEY_TYPE::KEY_ENTER, KEY_STATE::DOWN))
	{
		CSceneMgr::GetInst()->ChangeScene(SCENE_READY);
	}
}

void CSceneLogo::render(HDC _dc)
{
	if (NULL != m_pBackground)
	{
		BitBlt(_dc, 0, 0, m_pBackground->GetWidth(), m_pBackground->GetHeight(), m_pBackground->GetDC(), 0, 0, SRCCOPY);
	}
	CScene::render(_dc);
}

void CSceneLogo::ClickStartButton(CUIButton * _pButton)
{
	CSceneMgr::GetInst()->ChangeScene(SCENE_READY);
}

CSceneLogo::CSceneLogo()
{
}


CSceneLogo::~CSceneLogo()
{
}
