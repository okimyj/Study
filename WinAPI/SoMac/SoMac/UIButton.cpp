#include "stdafx.h"
#include "UIButton.h"
#include "Texture.h"

CUIButton::CUIButton(CTexture* _pNormal, CTexture* _pEnter, CTexture* _pDown)
	: m_pCurTexture(_pNormal)
	, m_pNormalTexture(_pNormal)
	, m_pEnterTexture(_pEnter)
	, m_pDownTexture(_pDown)
{
}


CUIButton::~CUIButton()
{
	SAFE_DEL(m_pNormalTexture);
	SAFE_DEL(m_pEnterTexture);
	SAFE_DEL(m_pDownTexture);
}

void CUIButton::init()
{
	m_pCurTexture = m_pNormalTexture;
}

void CUIButton::update()
{
}

void CUIButton::render(HDC _dc)
{
	if (!IsActive())
		return;

	if (NULL != m_pCurTexture)
	{
		TransparentBlt(_dc
			, m_ptPos.x - m_ptSize.x * m_ptPivot.x
			, m_ptPos.y - m_ptSize.y * m_ptPivot.y
			, m_ptSize.x
			, m_ptSize.y
			, m_pCurTexture->GetDC()
			, 0
			, 0
			, m_pCurTexture->GetWidth()
			, m_pCurTexture->GetHeight()
			, RGB(255, 0, 255));
	}
}


void CUIButton::OnPointerEnter()
{
	CUI::OnPointerEnter();
	// change enter image
	m_pCurTexture = m_pEnterTexture;
}

void CUIButton::OnPointerExit()
{
	CUI::OnPointerExit();
	// change normal image
	if(!IsPointerDown())
		m_pCurTexture = m_pNormalTexture;
}

void CUIButton::OnPointerDown(bool _isLeft)
{
	CUI::OnPointerDown(_isLeft);
	m_pCurTexture = m_pDownTexture;
	if (_isLeft)
		OnLButtonDown();
	else
		OnRButtonDown();
}

void CUIButton::OnPointerUp(bool _isLeft)
{
	
	if (IsPointerDown() && IsPointerEnter())
		OnPointerClick();

	CUI::OnPointerUp(_isLeft);

	if (IsPointerEnter())
		m_pCurTexture = m_pEnterTexture;
	else
		m_pCurTexture = m_pNormalTexture;

	if (_isLeft)
		OnLButtonUp();
	else
		OnRButtonUp();
	
}

void CUIButton::OnPointerClick()
{
	m_pClickCallback += this->What;
	m_pClickCallback(0);
}

void CUIButton::What(int _pButton)
{
}


void CUIButton::OnLButtonDown()
{
	m_bLButtonDown = true;
}

void CUIButton::OnLButtonUp()
{
	if (m_bLButtonDown && IsPointerEnter())
		OnLButtonClick();
	m_bLButtonDown = false;
}

void CUIButton::OnLButtonClick()
{
}

void CUIButton::OnRButtonDown()
{
	m_bRButtonDown = true;
}

void CUIButton::OnRButtonUp()
{
	if (m_bRButtonDown && IsPointerEnter())
		OnRButtonClick();
	m_bRButtonDown = false;
}

void CUIButton::OnRButtonClick()
{
}

