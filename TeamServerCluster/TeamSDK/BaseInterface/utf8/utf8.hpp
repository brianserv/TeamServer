/*! @file
	@brief UTF8�����жϺ�������
*/

#ifndef __UTILS_UTF8_HEADER__
#define __UTILS_UTF8_HEADER__

//! @brief ���UTF8�е��ַ�����
/*!
	���ش��е��ַ�����,��������ַ�������UTF8�Ĵ�����,����-1
*/
//@{
int  GetUtf8CharCount(
	const char *str		//!< ��NULL��β���ַ���
);
int  GetUtf8CharCount(
	const char *str,	//!< �ַ�����ʼ��ַ
	unsigned int len	//!< �ַ�������
);
//@}

#endif //__UTILS_UTF8_HEADER__
