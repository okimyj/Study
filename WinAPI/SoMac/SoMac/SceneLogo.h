#pragma once
#include "Scene.h"
class CTexture;
class CUIButton;
class CSceneLogo :
	public CScene
{
private:
	CTexture* m_pBackground;
public:
	virtual void enter();
	virtual void exit();
	virtual void update();
	virtual void render(HDC _dc);
	void ClickStartButton(CUIButton* _pButton);
public:
	CSceneLogo();
	virtual ~CSceneLogo();
};

