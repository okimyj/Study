#pragma once
#include "UI.h"
#include "Delegate.h"

class CUIButton :
	public CUI
{
public:
	CDelegate<void, int>	m_pClickCallback;			// touch event �� �߻����� �� ȣ���Ѵ�.
private:
	CTexture*		m_pCurTexture;
	CTexture*		m_pNormalTexture;
	CTexture*		m_pEnterTexture;
	CTexture*		m_pDownTexture;
	
protected:
	// L, R ��ư�� ���� �ؾ� �ϴ� ��쿡�� ��� �ϸ� ��. // UIButton.
	bool		m_bLButtonDown;				// ���� ��ư�� �ش� UI ���� ���� ����.
	bool		m_bRButtonDown;				// ������ ��ư�� �ش� UI ���� ���� ����.



public:
	virtual void init();
	virtual void render(HDC _dc);
	virtual void update();


public:
	virtual void OnPointerEnter();
	virtual void OnPointerExit();
	virtual void OnPointerDown(bool _isLeft);
	virtual void OnPointerUp(bool _isLeft);
	virtual void OnPointerClick();				// m_bPointerDown ���¿��� up �� ������ �� ȣ�� �ȴ�.
	void What(int _pButton);
protected:
	virtual void OnLButtonDown();
	virtual void OnLButtonUp();
	virtual void OnLButtonClick();

	virtual void OnRButtonDown();
	virtual void OnRButtonUp();
	virtual void OnRButtonClick();
	
public:
	CUIButton(CTexture* _pNormal, CTexture* _pEnter, CTexture* _pDown);
	virtual ~CUIButton();
};

