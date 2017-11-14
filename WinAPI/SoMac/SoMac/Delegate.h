#pragma once
#include "global.h"
template <typename ReturnType, typename Argument>
class CDelegate
{
	typedef ReturnType(*FUNCTION)(Argument);
	vector<FUNCTION>	m_events;
public:
	void operator +=(FUNCTION func) { return m_events.push_back(func); }
	void operator -=(FUNCTION func) 
	{
		vector<FUNCTION>::iterator iter = m_events.begin();
		for (iter; iter != m_events.end(); ++iter)
		{
			if (iter == func)
			{
				m_events.erase(iter);
			}
		}
		return m_events;
	}
	ReturnType operator () (Argument arg)
	{
		vector<FUNCTION>::iterator iter = m_events.begin();
		for (iter; iter != m_events.end(); ++iter)
			(*iter)(arg);
	}
public:
	CDelegate();
	~CDelegate();
};

