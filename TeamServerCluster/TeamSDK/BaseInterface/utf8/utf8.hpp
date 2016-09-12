/*! @file
	@brief UTF8长度判断函数定义
*/

#ifndef __UTILS_UTF8_HEADER__
#define __UTILS_UTF8_HEADER__

//! @brief 获得UTF8中的字符个数
/*!
	返回串中的字符个数,如果串中字符不符合UTF8的串规则,返回-1
*/
//@{
int  GetUtf8CharCount(
	const char *str		//!< 以NULL结尾的字符串
);
int  GetUtf8CharCount(
	const char *str,	//!< 字符串起始地址
	unsigned int len	//!< 字符串长度
);
//@}

#endif //__UTILS_UTF8_HEADER__
