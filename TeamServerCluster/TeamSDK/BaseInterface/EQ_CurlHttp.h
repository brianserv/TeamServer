#ifndef __CURL_HTTP_H__
#define __CURL_HTTP_H__

#include <string>

class CEQ_CurlHttp
{
public:
	CEQ_CurlHttp();
	virtual ~CEQ_CurlHttp();

public:
	int Curl_Http_Get(const std::string & strUrl, std::string & strHttpResponse);
	int Curl_Https_Get(const std::string & strUrl, std::string & strHttpResponse);
};

#endif// __CURL_HTTP_H__
