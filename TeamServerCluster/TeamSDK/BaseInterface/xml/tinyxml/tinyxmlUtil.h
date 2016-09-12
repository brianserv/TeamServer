#ifndef _TINYXML_UTIL_H_
#define _TINYXML_UTIL_H_

#include "tinyxml.h"
#include "../../EQUtils.h"

#define CONF_ELEM_NAME "Config"

class XmlElement;

typedef vector<XmlElement> XmlElemVec;


class XmlElement
{
	//���ո�ʽ�ַ�����ȡ
	//��ʽ��elem|elem|.....|[*][(attr)][elem]
	//ע�⣺��Ҫ���ַ����м����κοհ��ַ�
	//��|���Ҳ��������ӽڵ�
	//���������ѡ�ַ�������ֻ��ʹ������һ����ÿ���ĺ������£�
	//*��ʾ<T>value<T>��value
	//attr��ʾ<T attr=value/>��value
	//elem����ReadXMLNodes��ȡ��elem���ڵ���ӽڵ�����Ϊelem�Ľڵ��б�
	//����
	//<a> 
	//	<b attr=123>
	//		<c>
	//		<d>456</d>
	//		<c>
	//	</b>
	//</a> 
	//ReadXmlElemArray("a|b|c")���ص���XmlElement���͵�vector�����а�������c�ڵ��ָ��
	//ReadIntValue("a|b|(attr)")���ص���b��attr���Ե�ֵ123
	//ReadIntValue("a|b|c|d|*")���ص���d�ڵ��ֵ456

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//ע�⣺����������������߸��ݸ�ʽ�ַ����Ҳ�����Ӧλ�õ������������Ĭ�ϲ���def��ֵ��ReadXmlElemArray�򷵻ؿ�vector//
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
