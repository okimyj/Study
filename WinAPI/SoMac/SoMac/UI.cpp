#include "stdafx.h"
#include "UI.h"

CUI::CUI()
	: m_bInteractable(true)
	, m_bPointerEnter(false)
	, m_pParent(NULL)
	, m_listChild{}
	, m_ptLocalPos{0,0}
{
	m_ptPivot = { 0.f, 0.f };
}

CUI::~CUI()
{
}

void CUI::update()
{
	m_ptPos = m_ptLocalPos;
	if (NULL != m_pParent)
		m_ptPos += m_pParent->GetPos();
	child_update();
}

void CUI::child_update()
{
	list<CUI*>::iterator iter = m_listChild.begin();
	for (iter; iter != m_listChild.end(); ++iter)
		(*iter)->update();
}

void CUI::child_render(HDC _dc)
{
	list<CUI*>::iterator iter = m_listChild.begin();
	for (iter; iter != m_listChild.end(); ++iter)
		(*iter)->render(_dc);
}


void CUI::AddChild(CUI * _pUI)
{
	// 이미 내가 부모임.
	if (_pUI->m_pParent == this)
		return;

	m_listChild.push_back(_pUI);
	_pUI->SetParent(this);
}

// 자식 쪽에서 SetParent 할 때만 호출 한다. 다른 부모로 바꿀 때.. 
void CUI::RemoveChild(CUI * _pUI)
{
	m_listChild.remove(_pUI);
}

void CUI::SetParent(CUI * _pUI)
{
	// 이미 설정되어 있는 부모와 같으면 return.
	if (m_pParent == _pUI)
		return;
	// 이 전에 설정 되어 있던 부모에게 RemoveChild.
	if (NULL != m_pParent)
		m_pParent->RemoveChild(this);
	// 부모 set.
	m_pParent = _pUI;
	if(NULL != m_pParent)
		m_pParent->AddChild(this);
}