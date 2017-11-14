#include "stdafx.h"
#include "Scene.h"
#include "Obj.h"
CScene::CScene()
{
}


CScene::~CScene()
{
//	vector<CObj*>::iterator iter;
	for (int i = 0; i < OBJ_END; ++i)
	{
		SAFE_DEL_VEC(CObj*, m_vecObj[i]);
		/*iter = m_vecObj[i].begin();
		for (iter; iter != m_vecObj[i].end(); ++iter)
		{
			SAFE_DEL(*iter);
		}
		*/
	}
}

void CScene::render(HDC _dc)
{
	vector<CObj*>::iterator iter;
	for (int i = 0; i<OBJ_END; ++i)
	{
		iter = m_vecObj[i].begin();
		for (iter; iter != m_vecObj[i].end(); ++iter)
			(*iter)->render(_dc);
	}
}

bool CScene::AddObject(OBJ_TYPE _eType, CObj * _pObj)
{
	m_vecObj[_eType].push_back(_pObj);
	return true;
}

CObj * CScene::FindNearTarget(OBJ_TYPE _eType, tPoint _ptPos)
{
	CObj*	nearObj = NULL;
	float		minDist = 99999.f;
	for (int i = 0; i < m_vecObj[_eType].size(); ++i)
	{
		if (NULL != m_vecObj[_eType][i])
		{
			float dist = DISTANCE(m_vecObj[_eType][i]->GetPos(), _ptPos);
			if (dist < minDist)
				nearObj = m_vecObj[_eType][i];
		}
	}
	return nearObj;
}
