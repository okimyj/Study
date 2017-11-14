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
	// �̹� ���� �θ���.
	if (_pUI->m_pParent == this)
		return;

	m_listChild.push_back(_pUI);
	_pUI->SetParent(this);
}

// �ڽ� �ʿ��� SetParent �� ���� ȣ�� �Ѵ�. �ٸ� �θ�� �ٲ� ��.. 
void CUI::RemoveChild(CUI * _pUI)
{
	m_listChild.remove(_pUI);
}

void CUI::SetParent(CUI * _pUI)
{
	// �̹� �����Ǿ� �ִ� �θ�� ������ return.
	if (m_pParent == _pUI)
		return;
	// �� ���� ���� �Ǿ� �ִ� �θ𿡰� RemoveChild.
	if (NULL != m_pParent)
		m_pParent->RemoveChild(this);
	// �θ� set.
	m_pParent = _pUI;
	if(NULL != m_pParent)
		m_pParent->AddChild(this);
}