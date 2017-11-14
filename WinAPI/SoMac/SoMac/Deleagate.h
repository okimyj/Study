#pragma once
#include "global.h"
template <typename ReturnType, typename Argument>
class CDelegate
{
	typedef ReturnType (*Function)(Argument);
	vector<Function> m_events;
public:
	CDelegate() {}
	void operator += (Function _func)
	{
		m_events.push_back(_func);
	}
	void operator -=(Function _func)
	{
		vector<Function>::iterator iter = m_events.begin();
		for (iter; iter != m_events.end(); ++iter)
		{
			if (iter == _func)
			{
				m_events.erase(_func);
				break;
			}
		}
	}
	ReturnType operator()(Argument arg)
	{
		vector<Function>::iterator iter = m_events.begin();
		for (iter; iter != m_events.end(); ++iter)
		{
			(*iter)(arg);
		}
	}
	~CDelegate() {};
private:
	CDelegate(CDelegate&);
//	CDelegate& operator = (Delegate&);
};

