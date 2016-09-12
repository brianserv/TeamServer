﻿
#pragma once
#include "WebSocket.h"

class CWebSocketV8 : public CWebSocket
{
public:
  CWebSocketV8() { m_version = 8; }

  virtual bool Handshake(const char* data, size_t length, std::string &response);
  virtual const CWebSocketFrame* Ping(const char* data = NULL) const { return new CWebSocketFrame(WebSocketPing, data); }
  virtual const CWebSocketFrame* Pong(const char* data = NULL) const { return new CWebSocketFrame(WebSocketPong, data); }
  virtual const CWebSocketFrame* Close(WebSocketCloseReason reason = WebSocketCloseNormal, const std::string &message = "");
  virtual void Fail();

protected:
  virtual CWebSocketFrame* GetFrame(const char* data, uint64_t length);
  virtual CWebSocketFrame* GetFrame(WebSocketFrameOpcode opcode, const char* data = NULL, uint32_t length = 0, bool final = true, bool masked = false, int32_t mask = 0, int8_t extension = 0);
  virtual CWebSocketMessage* GetMessage();
  virtual const CWebSocketFrame* close(WebSocketCloseReason reason = WebSocketCloseNormal, const std::string &message = "");

  std::string calculateKey(const std::string &key);
};
