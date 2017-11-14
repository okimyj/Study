#include "stdafx.h"
#include "SceneGame.h"
#include "Player.h"
#include "Monster.h"
CSceneGame::CSceneGame()
{
}


CSceneGame::~CSceneGame()
{
}

void CSceneGame::enter()
{
	
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(tPoint{ WINSIZE_X / 2.f, WINSIZE_Y / 2.f });
	pPlayer->SetSize(tPoint{ 64, 70 });
	pPlayer->init();
	m_vecObj[OBJ_PLAYER].push_back(pPlayer);
	

	CMonster* pMonster = new CMonster;
	pMonster->SetPos(tPoint{ 100, 100 });
	pMonster->SetSize(tPoint{ 80, 80});
	pMonster->init();
	m_vecObj[OBJ_MONSTER].push_back(pMonster);
	
}

void CSceneGame::exit()
{
}

void CSceneGame::update()
{
	vector<CObj*>::iterator iter;
	for (int i = 0; i<OBJ_END; ++i)
	{
		iter = m_vecObj[i].begin();
		for (iter; iter != m_vecObj[i].end(); ++iter)
			(*iter)->update();
	}
}

void CSceneGame::render(HDC _dc)
{
	CScene::render(_dc);
}

