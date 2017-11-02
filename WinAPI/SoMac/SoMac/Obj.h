#pragma once
#include "global.h"
class CObj
{
private:
	wstring	m_strTag;
	tPoint	m_ptSize;
	tPoint	m_ptPos;
	
public :
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render(HDC _dc) = 0;

public:
	tPoint GetSize() { return m_ptSize; }
	void SetSize(tPoint _ptSize) { m_ptSize = _ptSize; }
	tPoint GetPos() { return m_ptPos; }
	void SetPos(tPoint _ptPos) { m_ptPos = _ptPos; }
	const wstring& GetTag() { return m_strTag; }
	void SetTag(const wstring& _strTag) { m_strTag = _strTag; }

public:
	CObj();
	virtual ~CObj();
};

