
#pragma once


// 握手协议 WebSocket 客户端请求，WebSocket 服务器端应答
//GET /chat HTTP/1.1
//Host: server.example.com
//Upgrade: websocket
//Connection: Upgrade
//Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==
//Origin: http://example.com
//Sec-WebSocket-Protocol: chat, superchat
//Sec-WebSocket-Version: 13

//HTTP/1.1 101 Switching Protocols
//Upgrade: websocket
//Connection: Upgrade
//Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=
//Sec-WebSocket-Protocol: chat


 //note:掩码加密算法:key 和 mask 串接之后经过 SHA-1 处理，处理后的数据再经过一次 Base64 编码
 //mask   = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";  
 //accept = base64( sha1( key + mask ) );

class CWebSocket;

class CWebSocketManager
{
public:
  static CWebSocket* Handle(const char* data, unsigned int &version, unsigned int length, std::string &response);
};
