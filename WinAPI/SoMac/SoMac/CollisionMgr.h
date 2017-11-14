#pragma once
#include "global.h"
class CObj;
class CCollider;
// �浹 ���̵�.
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
	vector<tColPair>	m_vecColPair;			// ���� �浹 üũ �� OBJ_TYPE �� pair�� ������ �ִ´�.
	map<DWORD, bool>		m_mapColUnion;
	/*
	// �迭, ����Ʈ�� �ε��� ������ ���������� Ž���� ������ �ƴ�.
	// map�� �ڷḦ �ִ� ����� ���� ������ Ž���� ����..
	stl map : 
		���� Ž�� Ʈ�� + �ڰ� ���� ���� Ž�� Ʈ��(���� �� Ʈ��) // log2^n ���� ã�� �� ����. 
		Ʈ����, �������� ���踦 ��Ÿ���µ� ���� ���� ��. (��������)
		�ڰ� ���� ���� Ž�� Ʈ�� : ���� Ž�� Ʈ�� �������� �ʹ� �������� ġ������ ������ ������ ���� ������� ������ ����ִ� �˰���.
		// http://www.cs.usfca.edu/~galles/visualization/RedBlack.html

		map ������ ���� ������ pair.
		find Ž�� ����� iterator 
		�ش礩 iterator�� �����  pair�� ����Ű��, 
		pair.first : key 
		pair.second : value 
		Ž�� ���н�  end iterator�� ��ȯ �Ѵ�. 
		���� ���� ���� Ŭ������ key�� ���� ��� �� ���۷����͸� �����϶�� ��.. �ѹ� �غ���.
		multimap : �ߺ� Ű���� ��� �ϴ� map.
						 �ߺ��� Ű�� ������ �ش� Ű�� ��� �� ������...
						�׳�  map�� �ߺ����� ���� Ű ���� �����Ѵ�.
	*/

public:
	void update();
public:
	void AddCollisionPair(const tColPair _pair) { m_vecColPair.push_back(_pair); }
	void Clear() { m_vecColPair.clear(); }
	void IsCollision(CCollider* _pLeft, CCollider* _pRight);
};

