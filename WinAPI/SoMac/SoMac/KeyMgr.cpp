#include "stdafx.h"
#include "KeyMgr.h"


CKeyMgr::CKeyMgr()
{
}


CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY_TYPE::END; ++i)
		m_arrKey[i].eState = KEY_STATE::NONE;

	m_arrKey[(int)KEY_TYPE::KEY_1].iVK = '1';
	m_arrKey[(int)KEY_TYPE::KEY_2].iVK = '2';
	m_arrKey[(int)KEY_TYPE::KEY_3].iVK = '3';
	m_arrKey[(int)KEY_TYPE::KEY_4].iVK = '4';
	m_arrKey[(int)KEY_TYPE::KEY_5].iVK = '5';
	m_arrKey[(int)KEY_TYPE::KEY_6].iVK = '6';
	m_arrKey[(int)KEY_TYPE::KEY_7].iVK = '7';
	m_arrKey[(int)KEY_TYPE::KEY_8].iVK = '8';
	m_arrKey[(int)KEY_TYPE::KEY_9].iVK = '9';
	m_arrKey[(int)KEY_TYPE::KEY_0].iVK = '0';
	m_arrKey[(int)KEY_TYPE::KEY_Q].iVK = 'Q';
	m_arrKey[(int)KEY_TYPE::KEY_W].iVK = 'W';
	m_arrKey[(int)KEY_TYPE::KEY_E].iVK = 'E';
	m_arrKey[(int)KEY_TYPE::KEY_R].iVK = 'R';
	m_arrKey[(int)KEY_TYPE::KEY_T].iVK = 'T';
	m_arrKey[(int)KEY_TYPE::KEY_Y].iVK = 'Y';
	m_arrKey[(int)KEY_TYPE::KEY_U].iVK = 'U';
	m_arrKey[(int)KEY_TYPE::KEY_I].iVK = 'I';
	m_arrKey[(int)KEY_TYPE::KEY_O].iVK = 'O';
	m_arrKey[(int)KEY_TYPE::KEY_P].iVK = 'P';
	m_arrKey[(int)KEY_TYPE::KEY_A].iVK = 'A';
	m_arrKey[(int)KEY_TYPE::KEY_S].iVK = 'S';
	m_arrKey[(int)KEY_TYPE::KEY_D].iVK = 'D';
	m_arrKey[(int)KEY_TYPE::KEY_F].iVK = 'F';
	m_arrKey[(int)KEY_TYPE::KEY_G].iVK = 'G';
	m_arrKey[(int)KEY_TYPE::KEY_H].iVK = 'H';
	m_arrKey[(int)KEY_TYPE::KEY_J].iVK = 'J';
	m_arrKey[(int)KEY_TYPE::KEY_K].iVK = 'K';
	m_arrKey[(int)KEY_TYPE::KEY_L].iVK = 'L';
	m_arrKey[(int)KEY_TYPE::KEY_Z].iVK = 'Z';
	m_arrKey[(int)KEY_TYPE::KEY_X].iVK = 'X';
	m_arrKey[(int)KEY_TYPE::KEY_C].iVK = 'C';
	m_arrKey[(int)KEY_TYPE::KEY_V].iVK = 'V';
	m_arrKey[(int)KEY_TYPE::KEY_B].iVK = 'B';
	m_arrKey[(int)KEY_TYPE::KEY_N].iVK = 'N';
	m_arrKey[(int)KEY_TYPE::KEY_M].iVK = 'M';
	m_arrKey[(int)KEY_TYPE::KEY_UP].iVK = VK_UP;
	m_arrKey[(int)KEY_TYPE::KEY_DOWN].iVK = VK_DOWN;
	m_arrKey[(int)KEY_TYPE::KEY_LEFT].iVK = VK_LEFT;
	m_arrKey[(int)KEY_TYPE::KEY_RIGHT].iVK = VK_RIGHT;
	m_arrKey[(int)KEY_TYPE::KEY_LSHIFT].iVK = VK_LSHIFT;
	m_arrKey[(int)KEY_TYPE::KEY_RSHIFT].iVK = VK_RSHIFT;
	m_arrKey[(int)KEY_TYPE::KEY_SPACE].iVK = VK_SPACE;
	m_arrKey[(int)KEY_TYPE::KEY_INSERT].iVK = VK_INSERT;
	m_arrKey[(int)KEY_TYPE::KEY_DEL].iVK = VK_DELETE;
	m_arrKey[(int)KEY_TYPE::KEY_HOME].iVK = VK_HOME;
	m_arrKey[(int)KEY_TYPE::KEY_END].iVK = VK_END;
	m_arrKey[(int)KEY_TYPE::KEY_PAGEUP].iVK = VK_PRIOR;
	m_arrKey[(int)KEY_TYPE::KEY_PAGEDOWN].iVK = VK_NEXT;
	m_arrKey[(int)KEY_TYPE::KEY_ESC].iVK = VK_ESCAPE;
	m_arrKey[(int)KEY_TYPE::KEY_F1].iVK = VK_F1;
	m_arrKey[(int)KEY_TYPE::KEY_F2].iVK = VK_F2;
	m_arrKey[(int)KEY_TYPE::KEY_F3].iVK = VK_F3;
	m_arrKey[(int)KEY_TYPE::KEY_F4].iVK = VK_F4;
	m_arrKey[(int)KEY_TYPE::KEY_F5].iVK = VK_F5;
	m_arrKey[(int)KEY_TYPE::KEY_F6].iVK = VK_F6;
	m_arrKey[(int)KEY_TYPE::KEY_F7].iVK = VK_F7;
	m_arrKey[(int)KEY_TYPE::KEY_F8].iVK = VK_F8;
	m_arrKey[(int)KEY_TYPE::KEY_F9].iVK = VK_F9;
	m_arrKey[(int)KEY_TYPE::KEY_F10].iVK = VK_F10;
	m_arrKey[(int)KEY_TYPE::KEY_F11].iVK = VK_F11;
	m_arrKey[(int)KEY_TYPE::KEY_F12].iVK = VK_F12;
	m_arrKey[(int)KEY_TYPE::KEY_NUM0].iVK = VK_NUMPAD0;
	m_arrKey[(int)KEY_TYPE::KEY_NUM1].iVK = VK_NUMPAD1;
	m_arrKey[(int)KEY_TYPE::KEY_NUM2].iVK = VK_NUMPAD2;
	m_arrKey[(int)KEY_TYPE::KEY_NUM3].iVK = VK_NUMPAD3;
	m_arrKey[(int)KEY_TYPE::KEY_NUM4].iVK = VK_NUMPAD4;
	m_arrKey[(int)KEY_TYPE::KEY_NUM5].iVK = VK_NUMPAD5;
	m_arrKey[(int)KEY_TYPE::KEY_NUM6].iVK = VK_NUMPAD6;
	m_arrKey[(int)KEY_TYPE::KEY_NUM7].iVK = VK_NUMPAD7;
	m_arrKey[(int)KEY_TYPE::KEY_NUM8].iVK = VK_NUMPAD8;
	m_arrKey[(int)KEY_TYPE::KEY_NUM9].iVK = VK_NUMPAD9;
	m_arrKey[(int)KEY_TYPE::KEY_ENTER].iVK = VK_RETURN;
	m_arrKey[(int)KEY_TYPE::KEY_CTRL].iVK = VK_CONTROL;
	m_arrKey[(int)KEY_TYPE::KEY_ALT].iVK = VK_MENU;
	m_arrKey[(int)KEY_TYPE::KEY_TAB].iVK = VK_TAB;
	m_arrKey[(int)KEY_TYPE::KEY_CAPS].iVK = VK_CAPITAL;
	m_arrKey[(int)KEY_TYPE::KEY_LBUTTON].iVK = VK_LBUTTON;
	m_arrKey[(int)KEY_TYPE::KEY_RBUTTON].iVK = VK_RBUTTON;
	m_arrKey[(int)KEY_TYPE::KEY_MBUTTON].iVK = VK_MBUTTON;
}

void CKeyMgr::update()
{
	// class enum은 int로 캐스팅 해주어야함.
	for (int i = 0; i < (int)KEY_TYPE::END; ++i)
	{
		if (GetAsyncKeyState(m_arrKey[i].iVK) & 0x8000)
		{
			// 키가 눌린 상태. 
			// 이전에 눌리지 않은 상태이거나, 키를 뗀 상태라면 이번에 처음 눌린거니 DOWN.
			if (KEY_STATE::NONE == m_arrKey[i].eState || KEY_STATE::UP == m_arrKey[i].eState)
				m_arrKey[i].eState = KEY_STATE::DOWN;
			// 이전에도 상태가 DOWN이였다면 계속 누르고 있는거니까 HOLD.
			else if(KEY_STATE::DOWN == m_arrKey[i].eState)
				m_arrKey[i].eState = KEY_STATE::HOLD;
		}
		else
		{
			// 키가 눌리지 않은 상태. 
			if (KEY_STATE::NONE == m_arrKey[i].eState)
				continue;

			if (KEY_STATE::UP == m_arrKey[i].eState)
				m_arrKey[i].eState = KEY_STATE::NONE;
			else  // 이전 상태가 down이나 hold 였을 경우.
				m_arrKey[i].eState = KEY_STATE::UP;
		}
	}

	// 현재 마우스 위치 저장.
	POINT pMouse{};
	GetCursorPos(&pMouse);
	ScreenToClient(g_hWnd, &pMouse);
	m_ptMouse = pMouse;
}

bool CKeyMgr::GetKeyState(KEY_TYPE _eType, KEY_STATE _eState)
{
	return _eState == m_arrKey[(int)_eType].eState;
}
