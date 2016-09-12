#pragma once


#ifndef  EQ_SINGLETON_FILE
#define  EQ_SINGLETON_FILE

template <typename T>
class CEQ_SingletonT
{
protected:
	CEQ_SingletonT(){};
	~CEQ_SingletonT(){};
public:
	static T &Instance()
	{
		static T instance;
		return instance;
	}
};

#endif

