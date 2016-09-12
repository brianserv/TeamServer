
#pragma once

#include "WebSocketV8.h"

class CWebSocketV13 : public CWebSocketV8
{
public:
  CWebSocketV13() { m_version = 13; }

  virtual bool Handshake(const char* data, size_t length, std::string &response);
  virtual const CWebSocketFrame* Close(WebSocketCloseReason reason = WebSocketCloseNormal, const std::string &message = "");
};
