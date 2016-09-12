#pragma once
#ifndef __GIRL_H__
#define __GIRL_H__

#include "../../FrameWork/BaseDefine.h"

class CGirl
{
public:
	CGirl();
	virtual ~CGirl();
	EQ_DECLARE_CACHE(CGirl)

public:
	inline void			setGirlId(int nGirlId) { m_nGirlID = nGirlId; };
	inline void			setGirlRoleId(int nGirlRoleId) { m_nGirlRoleId = nGirlRoleId; };
	inline void			setGirlName(string strGirlName) { m_strGirlName = strGirlName; };
	inline void			setPassword(string strPassword) { m_strPassword = strPassword; };
	inline void			setThirdId(string strThirdId) { m_strThirdId = strThirdId; };
	inline void			setCreateTime(int nCreateTime) { m_nCreateTime = nCreateTime; };

	inline void	        setPlayerIndex(int nPlayerIndex) { m_nPlayerIndex = nPlayerIndex; };
public:
	inline void			setRoomID(int nRoomID) { m_nRoomID = nRoomID; };
	inline void			setGameType(int nGameType) { m_nGameType = nGameType; };
public:
	inline void         setIsUsed(bool bIsUsed) { m_bIsUsed = bIsUsed; };

public:
	inline int		    getGirlId() { return m_nGirlID; };
	inline int		    getGirlRoleId() { return m_nGirlRoleId; };
	inline string		getGirlName() { return m_strGirlName; };
	inline string		getPassword() { return m_strPassword; };
	inline string		getThirdId() { return m_strThirdId; };
	inline int		    getCreateTime() { return m_nCreateTime; };
public:
	inline int	        GetPlayerIndex() { return m_nPlayerIndex; };

	inline  int			getGameType() { return m_nGameType; };
	inline  int			getRoomID() { return m_nRoomID; };

	inline bool         getIsUsed() { return m_bIsUsed; };

public:
	void SetGirlProperty(int    nGirlId,
		int nGirlRoleId,
		string	strGirlName,
		string	strPassword,
		string	strThirdId,
		int nCreateTime,
		int m_nPlayerIndex);

private:
	int         m_nGirlID;
	int	m_nGirlRoleId;
	string		m_strGirlName;
	string		m_strPassword;
	string		m_strThirdId;
	int	m_nCreateTime;
private:
	int			m_nGameType;
	int			m_nRoomID;
private:
	int         m_nPlayerIndex;
private:
	bool        m_bIsUsed;
};

#endif//__DB_GIRL_H__