#pragma once

#ifndef  EQ_HASHMAP_FILE
#define  EQ_HASHMAP_FILE
#if defined (_WIN32) || defined (_WIN64)
# define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 
#include <hash_map>
using namespace std;
#else
#include <ext/hash_map> 
using namespace __gnu_cxx; 
#endif
#include "EQ_Lock.h"


#if defined (_WIN32) || defined (_WIN64)

#define EQ_HASH_MAP(key,type,name)		\
	typedef stdext::hash_map<key,type>::iterator name##_it;\
	stdext::hash_map<key,type>    name##_obj;\
	inline int name##_size()\
	{\
		return (int)name##_obj.size();\
	};\
	inline bool name##_insert(key k,type t) \
	{\
		std::pair<name##_it ,bool>  bRet_pair;\
		bRet_pair = name##_obj.insert(std::make_pair(k,t));\
		return bRet_pair.second;\
	};\
	inline void  name##_remove(key k) \
	{ \
		name##_obj.erase(k); \
	};\
	inline void  name##_erase(name##_it it) \
	{ \
		name##_obj.erase(it); \
	};\
	inline bool name##_find(key k,type& t)\
	{\
		name##_it it = name##_obj.find(k);\
		if(it != name##_obj.end())\
		{\
			t =  it->second;\
			return true;\
		}\
		return false;\
	};\
	inline bool name##_empty()\
	{\
		return name##_obj.empty();\
	};\
	inline void name##_clear()\
	{\
		name##_obj.clear();\
	};\
	name##_it name##_begin()\
	{\
		return name##_obj.begin();\
	};\
	name##_it name##_end()\
	{\
		return name##_obj.end();\
	};

#else

#define EQ_HASH_MAP(key,type,name)		\
	typedef hash_map<key,type>::iterator name##_it;\
	hash_map<key,type>    name##_obj;\
	inline int name##_size()\
	{\
		return (int)name##_obj.size();\
	};\
	inline bool name##_insert(key k,type t) \
	{\
		std::pair<name##_it ,bool>  bRet_pair;\
		bRet_pair = name##_obj.insert(std::make_pair(k,t));\
		return bRet_pair.second;\
	};\
	inline void  name##_remove(key k) \
	{ \
		name##_obj.erase(k); \
	};\
	inline void  name##_erase(name##_it it) \
	{ \
		name##_obj.erase(it); \
	};\
	inline bool name##_find(key k,type& t)\
	{\
		name##_it it = name##_obj.find(k);\
		if(it != name##_obj.end())\
		{\
			t =  it->second;\
			return true;\
		}\
		return false;\
	};\
	inline bool name##_empty()\
	{\
		return name##_obj.empty();\
	};\
	inline void name##_clear()\
	{\
		name##_obj.clear();\
	};\
	name##_it name##_begin()\
	{\
		return name##_obj.begin();\
	};\
	name##_it name##_end()\
	{\
		return name##_obj.end();\
	};

#endif

#define EQ_HASH_MAP_LOCK(key,type,name) \
private:\
	CEQ_Lock   name##_lock;\
	EQ_HASH_MAP(key,type,name)

#define EQ_HASH_MAP_RWLOCK(key,type,name) \
private:\
	CEQ_RWLock   name##_lock;\
	EQ_HASH_MAP(key,type,name)


#endif