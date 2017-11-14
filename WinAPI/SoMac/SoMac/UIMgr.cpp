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
	// 현재 Scene 접근 
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
	// 현재 LBUTTON 이 down 이나 up 상태가 아니면 return.
	if (!(KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::DOWN) 
		|| KEY(KEY_TYPE::KEY_RBUTTON, KEY_STATE::DOWN)
		|| KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::UP)
		|| KEY(KEY_TYPE::KEY_RBUTTON, KEY_STATE::UP)))
		return;
	bool isLeftBtn = KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::DOWN) || KEY(KEY_TYPE::KEY_LBUTTON, KEY_STATE::UP);
	vector<CObj*>::iterator iter = _vecUI.begin();
	vector<CObj*>::iterator targetIter = _vecUI.end();			// 최종적으로 input을 가져갈 ui.
	CUI* pUI = NULL;
	// 맨 뒤에 있는(맨 앞쪽에 그려진)UI를 찾기 위해서 끝까지 loop.
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
	// targetIter가 end iter가 아니라면, 
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
		
		// input을 가져간 UI를 맨 위에 올려 놓기 위해 vector 내에서 지웠다 다시 넣음.
		CObj* pTargetUI = (*targetIter);
		_vecUI.erase(targetIter);
		_vecUI.push_back(pTargetUI);
	}


}

