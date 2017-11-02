#include "stdafx.h"
#include "Core.h"


CCore::CCore()
{
}


CCore::~CCore()
{
	ReleaseDC(g_hWnd, m_hdc);		// 얘는  winapi가 생성한 dc.
	DeleteDC(m_hMemDC);				// 사용자가 임의로 생성한 dc는 DeleteDC로 삭제해야 한다. 이유는 그냥 ms가 그렇게 시킴.
	DeleteObject(m_hMemBit);
}

void CCore::init()
{
	// main window 의 dc를 가져온다. 
	m_hdc = GetDC(g_hWnd);
	// m_hdc와 호환되는 memory dc 생성. (1,1) 의 비트맵을 보유하고 있다.  
	m_hMemDC = CreateCompatibleDC(m_hdc);
	// m_hdc 와 호환되는 memory bitmap 생성.
	m_hMemBit = CreateCompatibleBitmap(m_hdc, WINSIZE_X, WINSIZE_Y);
	// m_hMemDC에게 새로 생성한 bitmap을 준다. 그럼 원래 가지고 있던 것을 반환해줌.
	HGDIOBJ oldBitMap = SelectObject(m_hMemDC, m_hMemBit);
	// 원래 가지고 있던 것은 사용 할 일이 없으니 delete.
	DeleteObject(m_hMemBit);
	// Manager 들 init.

	
}

int CCore::run()
{
	update();
	render();
	return 0;
}

void CCore::update()
{
	// 각 Manager들의 update호출. 
}

void CCore::render()
{
	// 실제 윈도우 사이즈보다 top, left, right, bottom의 크기가 1픽셀씩 큰 rect를 memory dc에 그린다.
	Rectangle(m_hMemDC, -1, -1, WINSIZE_X + 1, WINSIZE_Y + 1);

	// m_hMemDC의 내용을 한꺼번에 main window dc에 그린다.
	BitBlt(m_hdc, 0, 0, WINSIZE_X, WINSIZE_Y, m_hMemDC, 0, 0, SRCCOPY);
}
