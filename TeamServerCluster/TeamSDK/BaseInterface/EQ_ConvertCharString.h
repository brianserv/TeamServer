#pragma once

#include "EQUtils.h"

#ifndef  EQ_ConvertCharString_FILE
#define  EQ_ConvertCharString_FILE
 

class CConvertCharString 
{  
public:  
	CConvertCharString();  
	virtual~ CConvertCharString();  
	char* U2G(const char* utf8);
	char* G2U(const char* gb2312);



	char* WcharToChar(const wchar_t* wp);  
	char* StringToChar(const string& s);  
	char* WstringToChar(const wstring& ws);  
	wchar_t* CharToWchar(const char* c);  
	wchar_t* WstringToWchar(const wstring& ws);  
	wchar_t* StringToWchar(const string& s);  
	wstring StringToWstring(const string& s);  
	string WstringToString(const wstring& ws); 

	wstring Utf8ToUnicode(const string str);
	string  UnicodeToUtf8(const wstring str);

	int G2U_linux(char* src,size_t nSrcLen,char* dest,size_t nDestLen);
	int U2G_linux(char* src,size_t nSrcLen,char* dest,size_t nDestLen);
	void Release();  
private:  
	char* m_char;  
	wchar_t* m_wchar;  
};  
#endif;  
