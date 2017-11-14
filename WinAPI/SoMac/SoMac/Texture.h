#pragma once
#include "global.h"
class CTexture
{
public:
	static CTexture* Load(const wstring& _strPath);

private:
	HDC				m_hDC;
	HBITMAP		m_hBitmap;
	float				m_fWidth;
	float				m_fHeight;

public:
	HDC GetDC() { return m_hDC; }
	float GetWidth() { return m_fWidth; }
	float GetHeight() { return m_fHeight; }
	

public:
	CTexture(HDC _dc, HBITMAP _hBitmap);
	~CTexture();
};

