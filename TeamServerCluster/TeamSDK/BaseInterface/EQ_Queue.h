#pragma once
#include "EQ_Lock.h"


template <typename T>
class CEQ_Queue
{
public:
	CEQ_Queue(void)
	{
	}
	~CEQ_Queue(void)
	{
		clear();
	}
public:
	
	inline int size()
	{
		EQ_AUTOLOCK(m_lock);
		return (int)m_queue.size();
	};
	inline bool empty()
	{
		EQ_AUTOLOCK(m_lock);
		return m_queue.empty();
	};
	
	inline void  push(T t)
	{
		EQ_AUTOLOCK(m_lock);
		m_queue.push(t);
	};
	
	inline bool  pop(T& t)
	{
		EQ_AUTOLOCK(m_lock);
		if(!m_queue.empty())
		{	
			t = m_queue.front();		
			m_queue.pop();
			return true;
		}
		return false;
	}

	inline void clear()
	{
		EQ_AUTOLOCK(m_lock);
		while (!m_queue.empty())
		{
			m_queue.pop();
		}
	};
protected:
	std::queue<T> m_queue;
	CEQ_Lock      m_lock; 
};


#define EQ_QUEUE(type,name)		\
private:	\
	std::queue<type>    name##_obj;\
public:\
	inline int name##_size()\
	{\
	return (int)name##_obj.size();\
	};\
	inline bool name##_empty()\
	{\
	return name##_obj.empty();\
	};\
	inline void name##_push(type t)\
	{\
	    name##_obj.push(t);\
	};\
	inline type name##_front()\
	{\
	return name##_obj.front();\
	};\
	inline void name##_pop()\
	{\
	    name##_obj.pop();\
	};

#define EQ_QUEUE_LOCK(type,name) \
private:\
	CEQ_Lock   name##_lock;\
	EQ_QUEUE(type,name)

