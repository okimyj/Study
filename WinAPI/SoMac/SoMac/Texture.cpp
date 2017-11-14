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
	// 먼저 로드 해보고 로드가 잘 되면 동적 할당 해서 생성한다. 
	// LoadImage() : bmp를 로드하는 api 기본 함수. 
	// HInstance 안넣어줘도 됨., fuLoad 값은 그냥 저런거니까 외울 필요는 없음. 알고만 있자. 
	HBITMAP hBit = (HBITMAP)LoadImage(NULL, _strPath.c_str(), IMAGE_BITMAP, 0,0, LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);
	if (NULL == hBit)
		return NULL;
	HDC dc = CreateCompatibleDC(CCore::GetInst()->GetMemDC());
	HGDIOBJ oldBitMap = SelectObject(dc, hBit);
	DeleteObject(oldBitMap);
	return new CTexture(dc, hBit);
}