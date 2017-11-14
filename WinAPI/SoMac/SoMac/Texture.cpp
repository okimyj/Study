#include "stdafx.h"
#include "Texture.h"
#include "Core.h"

CTexture::CTexture(HDC _dc, HBITMAP _hBitmap)
	: m_hDC(_dc)
	, m_hBitmap(_hBitmap)
{
	BITMAP tBit = {};
	GetObject(_hBitmap, sizeof(BITMAP), &tBit);
	m_fWidth = tBit.bmWidth;
	m_fHeight = tBit.bmHeight;

}

CTexture::~CTexture()
{
}



CTexture * CTexture::Load(const wstring & _strPath)
{
	// ���� �ε� �غ��� �ε尡 �� �Ǹ� ���� �Ҵ� �ؼ� �����Ѵ�. 
	// LoadImage() : bmp�� �ε��ϴ� api �⺻ �Լ�. 
	// HInstance �ȳ־��൵ ��., fuLoad ���� �׳� �����Ŵϱ� �ܿ� �ʿ�� ����. �˰� ����. 
	HBITMAP hBit = (HBITMAP)LoadImage(NULL, _strPath.c_str(), IMAGE_BITMAP, 0,0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);
	if (NULL == hBit)
		return NULL;
	HDC dc = CreateCompatibleDC(CCore::GetInst()->GetMemDC());
	HGDIOBJ oldBitMap = SelectObject(dc, hBit);
	DeleteObject(oldBitMap);
	return new CTexture(dc, hBit);
}