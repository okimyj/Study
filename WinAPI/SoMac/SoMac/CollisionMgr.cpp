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
	// ���� Scene�� �ִ� object ���� �浹�� üũ �Ѵ�. m_vecColPair�� �̿��ؼ� üũ �ؾ� �� �͵鸸 üũ. 
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurrentScene();
	if (NULL == pCurScene)
		return;
	for (int i = 0; i < m_vecColPair.size(); ++i)
	{
		const vector<CObj*>& vecLeft = pCurScene->GetObjVector(m_vecColPair[i].left);
		const vector<CObj*>& vecRight = pCurScene->GetObjVector(m_vecColPair[i].right);
		// const vector�� const iterator�� ��� �ؾ� �Ѵ�. 
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
				// �浹 id ����.
				uCollisionID uColID;
				


			}
		}

	}
	
}

void CCollisionMgr::IsCollision(CCollider * _pLeft, CCollider * _pRight)
{
}
