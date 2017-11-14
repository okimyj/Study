#pragma once
#include "global.h"
class CUI;
class CObj;
class CUIMgr
{
	SINGLE(CUIMgr);

private:
	CUI*		m_pCurPointerOn;

private:
	void CheckPointerOn(CUI* _pUI);
	void CheckPointerClick(vector<CObj*> _pUI);
public:
	void update();
};

