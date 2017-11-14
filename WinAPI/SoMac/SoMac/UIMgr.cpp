#include "stdafx.h"
#include "UIMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "UI.h"
#include "KeyMgr.h"

CUIMgr::CUIMgr()
{
}


CUIMgr::~CUIMgr()
{
}

void CUIMgr::update()
{
	// ���� Scene ���� 
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurrentScene();
	vector<CObj*> vecUIs = pCurScene->GetObjVector(OBJ_TYPE::OBJ_UI);
	tPoint ptMousePos = CKeyMgr::GetInst()->GetMousePos();

	for (int i = 0; i < vecUIs.size(); ++i)
	{
		CUI* pUI = (CUI*)vecUIs[i];
		if (!pUI->IsInteractable())
			continue;
		CheckPointerOn(pUI);
	}

	CheckPointerClick(vecUIs);
}


void CUIMgr::CheckPointerOn(CUI* _pUI)
{
	
	bool bPointerOn = _pUI->CheckPointerOn(true);
	if (bPointerOn)
	{
		if(!_pUI->IsPointerEnter())
			_pUI->OnPointerEnter();
	}
	else
	{
		if (_pUI->IsPointerEnter())
			_pUI->OnPointerExit();
	}
}


void CUIMgr::CheckPointerClick(vector<CObj*> _vecUI)
{
	// ���� LBUTTON �� down �̳� up ���°� �ƴϸ� return.
	if (!(KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::DOWN) 
		|| KEY(KEY_TYPE::KEY_RBUTTON, KEY_STATE::DOWN)
		|| KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::UP)
		|| KEY(KEY_TYPE::KEY_RBUTTON, KEY_STATE::UP)))
		return;
	bool isLeftBtn = KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::DOWN) || KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::UP);
	vector<CObj*>::iterator iter = _vecUI.begin();
	vector<CObj*>::iterator targetIter = _vecUI.end();			// ���������� input�� ������ ui.
	CUI* pUI = NULL;
	// �� �ڿ� �ִ�(�� ���ʿ� �׷���)UI�� ã�� ���ؼ� ������ loop.
	for (iter; iter != _vecUI.end(); ++iter)
	{
		pUI = (CUI*)(*iter);
		
		if (!pUI->IsInteractable())
			continue;
		
		if (pUI->IsPointerOn())
		{
			targetIter = iter;
		}
		else if (pUI->IsPointerDown())
			pUI->OnPointerUp(isLeftBtn);
		
	}
	// targetIter�� end iter�� �ƴ϶��, 
	if (targetIter != _vecUI.end())
	{
		if (KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::DOWN))
			((CUI*)(*targetIter))->OnPointerDown(true);
		else if (KEY(KEY_TYPE::KEY_RBUTTON, KEY_STATE::DOWN))
			((CUI*)(*targetIter))->OnPointerDown(false);
		else if (KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::UP))
			((CUI*)(*targetIter))->OnPointerUp(true);
		else if (KEY(KEY_TYPE::KEY_RBUTTON, KEY_STATE::UP))
			((CUI*)(*targetIter))->OnPointerUp(false);
		
		// input�� ������ UI�� �� ���� �÷� ���� ���� vector ������ ������ �ٽ� ����.
		CObj* pTargetUI = (*targetIter);
		_vecUI.erase(targetIter);
		_vecUI.push_back(pTargetUI);
	}


}

