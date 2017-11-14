#pragma once
#include "Obj.h"
class CUI :
	public CObj
{
private:
	bool		m_bInteractable;				// input을 받을 수 있는 상태인지. 
	bool		m_bActive;						// 보여지는 상태인지 아닌지.  false이면 그리지 않는다.
	bool		m_bPointerEnter;				// m_bPointerOn 이 true 일 때 해당 UI가 가장 위에 있을 때 .		// set true : OnPointerEnter, set false : OnPointerExit.
	bool		m_bPointerDown;				// mouse가 해당 ui 에서 눌린 상태.					// set true : OnPointerDown, set false : OnPointerUP.
	CUI*					m_pParent;
	list<CUI*>			m_listChild;
	tPoint				m_ptLocalPos;		// obj의 pt_mPos 는 world pos. 이건 부모의 위치로부터 떨어진 local pos.

public:
	bool IsPointerEnter() { return m_bPointerEnter; }
	bool IsPointerDown() { return m_bPointerDown; }
	bool IsInteractable() { return m_bInteractable; }

	void SetInteractable(bool _bEnable) { m_bInteractable = _bEnable; }
	bool IsParent() { return NULL == m_pParent; }

	void SetActive(bool _bActive) { m_bActive = _bActive; }
	bool IsActive() { return m_bActive; }

	void AddChild(CUI* _pUI);
	void RemoveChild(CUI* _pUI);
	void SetParent(CUI* _pUI);

	tPoint GetLocalPos() { return m_ptLocalPos; }

protected:
	void child_update();
	void child_render(HDC _dc);

public:
	virtual void init() = 0;
	virtual void render(HDC _dc) = 0;
	virtual void update();

public:
	virtual void OnPointerEnter() { m_bPointerEnter = true; }
	virtual void OnPointerExit() { m_bPointerEnter = false; }
	virtual void OnPointerDown(bool _isLeft) { m_bPointerDown = true; }
	virtual void OnPointerUp(bool _isLeft) { m_bPointerDown = false; }
	virtual void OnPointerClick() {}



public:
	CUI();
	virtual ~CUI();
};

