#include "stdafx.h"
#include "Core.h"


CCore::CCore()
{
}


CCore::~CCore()
{
	ReleaseDC(g_hWnd, m_hdc);		// ���  winapi�� ������ dc.
	DeleteDC(m_hMemDC);				// ����ڰ� ���Ƿ� ������ dc�� DeleteDC�� �����ؾ� �Ѵ�. ������ �׳� ms�� �׷��� ��Ŵ.
	DeleteObject(m_hMemBit);
}

void CCore::init()
{
	// main window �� dc�� �����´�. 
	m_hdc = GetDC(g_hWnd);
	// m_hdc�� ȣȯ�Ǵ� memory dc ����. (1,1) �� ��Ʈ���� �����ϰ� �ִ�.  
	m_hMemDC = CreateCompatibleDC(m_hdc);
	// m_hdc �� ȣȯ�Ǵ� memory bitmap ����.
	m_hMemBit = CreateCompatibleBitmap(m_hdc, WINSIZE_X, WINSIZE_Y);
	// m_hMemDC���� ���� ������ bitmap�� �ش�. �׷� ���� ������ �ִ� ���� ��ȯ����.
	HGDIOBJ oldBitMap = SelectObject(m_hMemDC, m_hMemBit);
	// ���� ������ �ִ� ���� ��� �� ���� ������ delete.
	DeleteObject(m_hMemBit);
	// Manager �� init.

	
}

int CCore::run()
{
	update();
	render();
	return 0;
}

void CCore::update()
{
	// �� Manager���� updateȣ��. 
}

void CCore::render()
{
	// ���� ������ ������� top, left, right, bottom�� ũ�Ⱑ 1�ȼ��� ū rect�� memory dc�� �׸���.
	Rectangle(m_hMemDC, -1, -1, WINSIZE_X + 1, WINSIZE_Y + 1);

	// m_hMemDC�� ������ �Ѳ����� main window dc�� �׸���.
	BitBlt(m_hdc, 0, 0, WINSIZE_X, WINSIZE_Y, m_hMemDC, 0, 0, SRCCOPY);
}
