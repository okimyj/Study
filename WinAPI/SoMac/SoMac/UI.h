#pragma once
#include "Obj.h"
class CUI :
	public CObj
{
private:
	bool		m_bInteractable;				// input�� ���� �� �ִ� ��������. 
	bool		m_bActive;						// �������� �������� �ƴ���.  false�̸� �׸��� �ʴ´�.
	bool		m_bPointerEnter;				// m_bPointerOn �� true �� �� �ش� UI�� ���� ���� ���� �� .		// set true : OnPointerEnter, set false : OnPointerExit.
	bool		m_bPointerDown;				// mouse�� �ش� ui ���� ���� ����.					// set true : OnPointerDown, set false : OnPointerUP.
	CUI*					m_pParent;
	list<CUI*>			m_listChild;
	tPoint				m_ptLocalPos;		// obj�� pt_mPos �� world pos. �̰� �θ��� ��ġ�κ��� ������ local pos.

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

