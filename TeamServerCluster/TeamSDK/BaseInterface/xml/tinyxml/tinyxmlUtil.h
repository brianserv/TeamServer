#ifndef _TINYXML_UTIL_H_
#define _TINYXML_UTIL_H_

#include "tinyxml.h"
#include "../../EQUtils.h"

#define CONF_ELEM_NAME "Config"

class XmlElement;

typedef vector<XmlElement> XmlElemVec;


class XmlElement
{
	//按照格式字符串读取
	//格式：elem|elem|.....|[*][(attr)][elem]
	//注意：不要在字符串中加入任何空白字符
	//“|”右侧是左侧的子节点
	//最后三个可选字符必须且只能使用其中一个，每个的含义如下：
	//*表示<T>value<T>的value
	//attr表示<T attr=value/>的value
	//elem用于ReadXMLNodes获取此elem父节点的子节点中名为elem的节点列表
	//例如
	//<a> 
	//	<b attr=123>
	//		<c>
	//		<d>456</d>
	//		<c>
	//	</b>
	//</a> 
	//ReadXmlElemArray("a|b|c")返回的是XmlElement类型的vector，其中包含两个c节点的指针
	//ReadIntValue("a|b|(attr)")返回的是b的attr属性的值123
	//ReadIntValue("a|b|c|d|*")返回的是d节点的值456

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//注意：如遇到出错情况或者根据格式字符串找不到相应位置的情况函数返回默认参数def的值，ReadXmlElemArray则返回空vector//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	XmlElement():m_elem(NULL){}
	XmlElement(TiXmlNode* elem):m_elem(elem){}
	~XmlElement();

	bool LoadConfigFile(const char *filename);
	bool LoadConfigFile(const wchar_t *filename);

	void SetElem(TiXmlNode* elem){m_elem=elem;}
	TiXmlNode* GetElem()  { return m_elem; }

public:
	int ReadIntValue(std::string str,int def=0);
	float ReadFloatValue(std::string str,float def=0);
	double ReadDoubleValue(std::string str,double def=0);
	std::string ReadStringValue(std::string str,std::string def="");
	bool ReadXmlElemArray( XmlElemVec& elemArray, std::string str );

	int ReadIntAttr(const char* str, const char* attr, int def=0);
	float ReadFloatAttr(const char* str, const char* attr,float def=0);
	double ReadDoubleAttr(const char* str, const char* attr,double def=0);
	std::string ReadStringAttr(const char* str, const char* attr, std::string def="");

	bool Parse(const char * p);

protected:
	TiXmlNode* GetNode(std::string str);
	std::string GetAttrName(std::string str);
	bool IsGetText(std::string str);
	

private:
	TiXmlNode* m_elem;
	
};
#endif // _TINYXML_UTIL_H_
