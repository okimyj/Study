#pragma once
#include "global.h"
class CObj;
class CCollider;
// 충돌 아이디.
union uCollisionID
{
	DWORD dwID;
	struct {
		WORD leftID;
		WORD rightID;
	};
};
class CCollisionMgr
{
	SINGLE(CCollisionMgr);
private:
	vector<tColPair>	m_vecColPair;			// 서로 충돌 체크 할 OBJ_TYPE 을 pair로 가지고 있는다.
	map<DWORD, bool>		m_mapColUnion;
	/*
	// 배열, 리스트는 인덱싱 접근이 빠른것이지 탐색이 빠른게 아님.
	// map은 자료를 넣는 비용은 많이 들지만 탐색이 빠름..
	stl map : 
		이진 탐색 트리 + 자가 균형 이진 탐색 트리(레드 블랙 트리) // log2^n 으로 찾을 수 있음. 
		트리란, 계층적인 관계를 나타내는데 가장 편리한 것. (폴더구조)
		자가 균형 이진 탐색 트리 : 이진 탐색 트리 구조에서 너무 한쪽으로 치우쳐진 구조가 나오는 것을 어느정도 균형을 잡아주는 알고리즘.
		// http://www.cs.usfca.edu/~galles/visualization/RedBlack.html

		map 데이터 삽입 단위는 pair.
		find 탐색 결과는 iterator 
		해당ㄹ iterator는 노드의  pair를 가르키고, 
		pair.first : key 
		pair.second : value 
		탐색 실패시  end iterator를 반환 한다. 
		만약 내가 만든 클래스를 key로 넣을 경우 비교 오퍼레이터를 구현하라고 뜸.. 한번 해보자.
		multimap : 중복 키값을 허용 하는 map.
						 중복된 키가 들어오면 해당 키에 계속 쭉 연결함...
						그냥  map은 중복으로 들어온 키 값은 무시한다.
	*/

public:
	void update();
public:
	void AddCollisionPair(const tColPair _pair) { m_vecColPair.push_back(_pair); }
	void Clear() { m_vecColPair.clear(); }
	void IsCollision(CCollider* _pLeft, CCollider* _pRight);
};

