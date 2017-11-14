#include "stdafx.h"
#include "CollisionMgr.h"

#include "SceneMgr.h"
#include "Scene.h"
#include "Obj.h"

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::update()
{
	// 현재 Scene에 있는 object 들의 충돌을 체크 한다. m_vecColPair를 이용해서 체크 해야 할 것들만 체크. 
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurrentScene();
	if (NULL == pCurScene)
		return;
	for (int i = 0; i < m_vecColPair.size(); ++i)
	{
		const vector<CObj*>& vecLeft = pCurScene->GetObjVector(m_vecColPair[i].left);
		const vector<CObj*>& vecRight = pCurScene->GetObjVector(m_vecColPair[i].right);
		// const vector는 const iterator를 사용 해야 한다. 
		vector<CObj*>::const_iterator leftIter = vecLeft.begin();
		vector<CObj*>::const_iterator rightIter;
		for (leftIter; leftIter != vecLeft.end(); ++leftIter)
		{
			if (!(*leftIter)->HasCollider())
				continue;
			rightIter = vecRight.begin();
			for (rightIter; rightIter != vecRight.end(); ++rightIter)
			{
				if (!(*rightIter)->HasCollider())
					continue;
				CCollider* pLeftCollider = (*leftIter)->GetCollider();
				CCollider* pRightCollider = (*rightIter)->GetCollider();
				// 충돌 id 생성.
				uCollisionID uColID;
				


			}
		}

	}
	
}

void CCollisionMgr::IsCollision(CCollider * _pLeft, CCollider * _pRight)
{
}
