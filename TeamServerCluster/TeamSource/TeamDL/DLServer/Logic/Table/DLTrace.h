#ifndef __DL_TRACE_H__
#define __DL_TRACE_H__

#include "../../FrameWork/BaseDefine.h"

class CDLTrace
{
public:
	CDLTrace();
	virtual ~CDLTrace();
	EQ_DECLARE_CACHE(CDLTrace)

		inline void			setRoleId(__INT32 nRoleId) { m_nRoleId = nRoleId; };
	inline void			setCostType(int nCostType) { m_nCostType = nCostType; };
	inline void         setUnBindChip(__INT32 nUnBindChip) { m_nUnbindChip = nUnBindChip; };
	inline void         setUnBindPink(__INT32 nUnBinkPink) { m_nUnbindPink = nUnBinkPink; };
	inline void         setBindChip(__INT32 nBindChip) { m_nBindChip = nBindChip; };
	inline void         setBindPink(__INT32 nBindPink) { m_nBindPink = nBindPink; };
	inline void			setDescribe(string strDescribe) { m_strDescribe = strDescribe; };

public:
	inline __INT32		getRoleId() { return m_nRoleId; };
	inline int			getCostType() { return m_nCostType; };
	inline __INT32     getUnBindChip() { return m_nUnbindChip; };
	inline __INT32     getUnBindPink() { return m_nUnbindPink; };
	inline __INT32     getBindChip() { return m_nBindChip; };
	inline __INT32     getBindPink() { return m_nBindPink; };
	inline string		getDescribe() { return m_strDescribe; };

public:
	void		SetTraceProperty(__INT32 nRoleId,
		int		 nCostType,
		__INT32	 nUnbindChip,
		__INT32	 nUnbindPink,
		__INT32	 nBindChip,
		__INT32	 nBindPink,
		string strDescribe);

private:
	__INT32	m_nRoleId;
	int			m_nCostType;
	__INT32	m_nUnbindChip;
	__INT32	m_nUnbindPink;
	__INT32	m_nBindChip;
	__INT32	m_nBindPink;
	string		m_strDescribe;
};

#endif//__DL_TRACE_H__