#pragma once
#ifndef __TEXTTABLE_H__
#define __TEXTTABLE_H__

#include "../EQUtils.h"

typedef unsigned char	uchar;
typedef unsigned short 	ushort;
typedef unsigned int	uint;
typedef unsigned long 	ulong;

class  CTextTable
{
public:
    class  CTableItem
    {
    public:
        CTableItem(const char* szItemString) {m_szItemString = szItemString;}
        bool IsValid() const                { return m_szItemString[0]!=0; }
        operator const       char*() const  { return m_szItemString; }
        const char*          Str() const    { return m_szItemString; }
        const char*          SafeStr()const { return m_szItemString?m_szItemString:""; }
        const bool           Bool() const   { return                 atoi(m_szItemString)!=0; }
        const char           Char() const   { return (char)          m_szItemString[0]; }
        const uchar  Byte() const   { return (uchar) atoi(m_szItemString); }
        const short          Short() const  { return (short)         atoi(m_szItemString); }
        const ushort Word() const   { return (ushort)atoi(m_szItemString); }
        const int            Int() const    { return                 atoi(m_szItemString); }
        const uint   UInt() const   { return (uint)  atoi(m_szItemString); }
        const long           Long() const   { return                 atol(m_szItemString); }
        const uint  DWord() const  { return (uint) atol(m_szItemString); }
        const float          Float() const  { return (float)         atof(m_szItemString); }
        const double         Double() const { return                 atof(m_szItemString); }
    private:
        const char* m_szItemString;
    };
    class  CTableLine
    {
    protected:
        CTableLine():m_pTable(NULL),m_iLineIdx(0) {}
        void SetLine(CTextTable* pTable, int iLineIdx)   { m_pTable = pTable; m_iLineIdx = iLineIdx;}
    public:
        friend class CTextTable;

        const CTableItem operator[](int nIndex) const
        {
			//printf("m_iLineIdx[%d] nIndex[%d]",m_iLineIdx,nIndex);

            return CTableItem(m_pTable->GetString(m_iLineIdx, nIndex));
        }
        const CTableItem operator[](const char* szIdx) const
        {
            return CTableItem(m_pTable->GetString(m_iLineIdx, szIdx));
        }
    private:
        CTextTable*  m_pTable;
        int          m_iLineIdx;
    };

protected:
    CTextTable(char cSeparator);
    virtual ~CTextTable();
    bool ParseTextTable();

    bool WriteCellValue(int iLine, int iRow, const char* vValue, int nSize);

public:

    bool LoadTableFile(const char* szFilename);

    bool CreateTableFile(const char* szFilename, const int iLine, const int iRow);

    bool Save();
    bool SaveAs(const char* szFilename);


    void Clear();


    bool IsLoaded()                                 { return m_pContent != NULL; }

    const CTableLine& operator[](int nIndex) const   { return m_pLines[nIndex]; }
    const CTableLine& operator[](const char* szIdx) const;

    const char* GetString(int iLine, int iRow) const;
    const char* GetString(int iLine, const char* szRowIdx) const;
    const char* GetString(const char* szLineIdx, const char* szRowIdx) const;

    bool Char  (int iLine, int iRow, char          & vValue) const;
    bool Byte  (int iLine, int iRow, uchar & vValue) const;
    bool Short (int iLine, int iRow, short         & vValue) const;
    bool Word  (int iLine, int iRow, ushort& vValue) const;
    bool Int   (int iLine, int iRow, int           & vValue) const;
    bool UInt  (int iLine, int iRow, uint  & vValue) const;
    bool Long  (int iLine, int iRow, long          & vValue) const;
    bool DWord (int iLine, int iRow, uint & vValue) const;
    bool Float (int iLine, int iRow, float         & vValue) const;
    bool Double(int iLine, int iRow, double        & vValue) const;

    bool WriteChar  (int iLine, int iRow, const char            vValue);
    bool WriteByte  (int iLine, int iRow, const uchar   vValue);
    bool WriteShort (int iLine, int iRow, const short           vValue);
    bool WriteWord  (int iLine, int iRow, const ushort  vValue);
    bool WriteInt   (int iLine, int iRow, const int             vValue);
    bool WriteUInt  (int iLine, int iRow, const uint    vValue);
    bool WriteLong  (int iLine, int iRow, const long            vValue);
    bool WriteDWord (int iLine, int iRow, const uint   vValue);
    bool WriteFloat (int iLine, int iRow, const float           vValue);
    bool WriteDouble(int iLine, int iRow, const double          vValue);
    bool WriteStr   (int iLine, int iRow, const char*           vValue);

    int GetLineCount()  { return m_iLineCount; }
    int GetMaxRow()     { return m_iMaxRow; }

    void SetTitleLine(int iIdx)     { m_iTitleLine=iIdx; }
    int  GetTitleLine()             { return m_iTitleLine; }
    void SetTitleRow(int iIdx)      { m_iTitleRow=iIdx; }
    int  GetTitleRow()              { return m_iTitleRow; }

    bool FindPosByString(const char* szString, int& iLine, int& iRow);
    int FindLineByString(const char* szString);
    int FindRowByString(const char* szString);

protected:
    char        	m_cSeparator;
    std::string	m_strFilename;
    char*       	m_pContent;
    char**      	m_pItems;
    CTableLine*  	m_pLines;
    CTableLine   	m_InvalidLine;

    int         m_iLineCount;
    int         m_iMaxRow;

    int         m_iTitleLine;
    int         m_iTitleRow;

    int         m_iContentSize;
    int         m_iContentCur;

    bool        m_bOpenMode;
};

class  CTextCsv : public CTextTable
{
public:
    CTextCsv() : CTextTable(',') {}
    virtual ~CTextCsv(){}
};

class  CTextTableLoader
{
public:
    enum ETableReadState
    {
        TRS_SKIP = -1,
        TRS_EXIT =  0,
        TRS_OK   =  1,
    };

    struct  CTableObject
    {

    };

    CTextTableLoader();
    virtual ~CTextTableLoader();

    bool Load(const char * szLoadFilename);

    bool Reload();

    bool ReloadByFilename(const char * szLoadFilename);

    void Clear();

    CTableObject* Find(int iIdx);

    CTableObject* At(int iIdx);

protected:

    virtual bool OnSetTitleLine(CTextCsv& csv) { return false; }

    virtual bool OnReadStart() { return false; }

    virtual bool OnReadFinish() { return false; }

    virtual ETableReadState OnReadLineStart(int iLine, const CTextTable::CTableLine& line) { return TRS_EXIT; }

    virtual ETableReadState OnReadLineFinish(int iLine, CTableObject* pItem) { return TRS_EXIT; }

    virtual CTableObject* OnCreateLineObject() { return NULL; }

    virtual void OnDestroyLineObject(CTableObject* pObj) { delete pObj; }

    virtual ETableReadState OnReadLineItem(int iLine, const char* szItemTitle, const CTextTable::CTableItem& itemLine, CTableObject* pTObj) { return TRS_EXIT; }

protected:
   std::string m_strTableFilename;
	std::vector<CTableObject*>   m_table;
	std::map<int, CTableObject*> m_map;

};

#endif//__TEXTTABLE_H__
