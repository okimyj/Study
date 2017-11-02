#pragma once
#include "global.h"
class CCore
{
	SINGLE(CCore);

private :
	HDC			m_hdc;
	HDC			m_hMemDC;
	HBITMAP	m_hMemBit;
public:
	void init();
	int run();

private:
	void update();
	void render();

public:
	HDC GetWndDC() { return m_hdc; }
	HDC GetMemDC() { return m_hMemDC; }
};

