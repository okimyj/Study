#include "stdafx.h"
#include "Scene.h"
#include "Obj.h"
CScene::CScene()
{
}


CScene::~CScene()
{
	vector<CObj*>::iterator iter;
	for (int i = 0; i < OBJ_END; ++i)
	{
		iter = m_vecObj[i].begin();
		for (iter; iter != m_vecObj[i].end(); ++iter)
		{
			SAFE_DEL(*iter);
		}
	}
}

bool CScene::AddObject(OBJ_TYPE _eType, CObj * _pObj)
{
	m_vecObj[_eType].push_back(_pObj);
	return true;
}
