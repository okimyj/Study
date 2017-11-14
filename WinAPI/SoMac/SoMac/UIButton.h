#pragma once
#include "UI.h"
#include "Delegate.h"

class CUIButton :
	public CUI
{
public:
	CDelegate<void, int>	m_pClickCallback;			// touch event 가 발생했을 떄 호출한다.
private:
	CTexture*		m_pCurTexture;
	CTexture*		m_pNormalTexture;
	CTexture*		m_pEnterTexture;
	CTexture*		m_pDownTexture;
	
protected:
	// L, R 버튼을 구분 해야 하는 경우에만 사용 하면 됨. // UIButton.
	bool		m_bLButtonDown;				// 왼쪽 버튼을 해당 UI 에서 누른 상태.
	bool		m_bRButtonDown;				// 오른쪽 버튼을 해당 UI 에서 누른 상태.



public:
	virtual void init();
	virtual void render(HDC _dc);
	virtual void update();


public:
	virtual void OnPointerEnter();
	virtual void OnPointerExit();
	virtual void OnPointerDown(bool _isLeft);
	virtual void OnPointerUp(bool _isLeft);
	virtual void OnPointerClick();				// m_bPointerDown 상태에서 up 이 들어왔을 때 호출 된다.
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

