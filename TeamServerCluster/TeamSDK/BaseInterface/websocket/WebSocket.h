#pragma once

#if defined (_WIN32) || defined (_WIN64)
#include "sysdef.h"
#pragma  warning(disable: 4200)
#else
#include <stdint.h>
#endif

#include <vector>
#include "EQ_Log.h"

//CEQ_Log    g_EQLog;

// WebSocket ������
//|Opcode  | Meaning                             | Reference |
//-+--------+-------------------------------------+-----------|
//| 0      | Continuation Frame                  | RFC 6455  |
//-+--------+-------------------------------------+-----------|
//| 1      | Text Frame                          | RFC 6455  |
//-+--------+-------------------------------------+-----------|
//| 2      | Binary Frame                        | RFC 6455  |
//-+--------+-------------------------------------+-----------|
//| 8      | Connection Close Frame              | RFC 6455  |
//-+--------+-------------------------------------+-----------|
//| 9      | Ping Frame                          | RFC 6455  |
//-+--------+-------------------------------------+-----------|
//| 10     | Pong Frame                          | RFC 6455  |
//-+--------+-------------------------------------+-----------|

enum WebSocketFrameOpcode
{
	WebSocketContinuationFrame = 0x00,
	WebSocketTextFrame = 0x01,
	WebSocketBinaryFrame = 0x02,
	//0x3 - 0x7 are reserved for non-control frames
	WebSocketConnectionClose = 0x08,
	WebSocketPing = 0x09,
	WebSocketPong = 0x0A,
	//0xB - 0xF are reserved for control frames
	WebSocketUnknownFrame = 0x10
};

enum WebSocketState
{
	WebSocketStateNotConnected = 0,
	WebSocketStateHandshaking = 1,
	WebSocketStateConnected = 2,
	WebSocketStateClosing = 3,
	WebSocketStateClosed = 4
};

enum WebSocketCloseReason
{
	WebSocketCloseNormal = 1000,
	WebSocketCloseLeaving = 1001,
	WebSocketCloseProtocolError = 1002,
	WebSocketCloseInvalidData = 1003,
	WebSocketCloseFrameTooLarge = 1004,
	// Reserved status code       = 1005,
	// Reserved status code       = 1006,
	WebSocketCloseInvalidUtf8 = 1007
};

// WebSocket ֡�ṹ
//0                   1                   2                   3
//0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//+-+-+-+-+-------+-+-------------+-------------------------------+
//|F|R|R|R| opcode|M| Payload len |    Extended payload length    |
//|I|S|S|S|  (4)  |A|     (7)     |             (16/64)           |
//|N|V|V|V|       |S|             |   (if payload len==126/127)   |
//| |1|2|3|       |K|             |                               |
//+-+-+-+-+-------+-+-------------+ - - - - - - - - - - - - - - - +
//|     Extended payload length continued, if payload len == 127  |
//+ - - - - - - - - - - - - - - - +-------------------------------+
//|                               |Masking-key, if MASK set to 1  |
//+-------------------------------+-------------------------------+
//| Masking-key (continued)       |          Payload Data         |
//+-------------------------------- - - - - - - - - - - - - - - - +
//:                     Payload Data continued ...                :
//+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
//|                     Payload Data continued ...                |
//+---------------------------------------------------------------+

class CWebSocketFrame
{
public:
	CWebSocketFrame(const char* data, uint64_t length);
	CWebSocketFrame(WebSocketFrameOpcode opcode, const char* data = NULL, uint32_t length = 0, bool final = true, bool masked = false, int32_t mask = 0, int8_t extension = 0);
	virtual ~CWebSocketFrame();

	virtual bool IsValid() const { return m_valid; }
	virtual uint64_t GetFrameLength() const { return m_lengthFrame; }
	virtual bool IsFinal() const { return m_final; }
	virtual int8_t GetExtension() const { return m_extension; }
	virtual WebSocketFrameOpcode GetOpcode() const { return m_opcode; }
	virtual bool IsControlFrame() const { return (m_valid && (m_opcode & 0x8) == 0x8); }
	virtual bool IsMasekd() const { return m_masked; }
	virtual uint64_t GetLength() const { return m_length; }
	virtual int32_t GetMask() const { return m_mask; }
	virtual const char* GetFrameData() const { return m_data; }
	virtual const char* GetApplicationData() const { return m_applicationData; }

protected:
	bool m_free;
	const char *m_data;
	uint64_t m_lengthFrame;
	uint64_t m_length;
	bool m_valid;
	bool m_final;
	int8_t m_extension;
	WebSocketFrameOpcode m_opcode;
	bool m_masked;
	int32_t m_mask;
	char *m_applicationData;

private:
	void reset();
};

class CWebSocketMessage
{
public:
	CWebSocketMessage();
	virtual ~CWebSocketMessage();

	virtual bool IsFragmented() const { return m_fragmented; }
	virtual bool IsComplete() const { return m_complete; }

	virtual bool AddFrame(const CWebSocketFrame* frame);
	virtual const std::vector<const CWebSocketFrame *>& GetFrames() const { return m_frames; }

	virtual void Clear();

protected:
	std::vector<const CWebSocketFrame *> m_frames;
	bool m_fragmented;
	bool m_complete;
};

class CWebSocket
{
public:
	CWebSocket() { m_state = WebSocketStateNotConnected; m_message = NULL; }
	virtual ~CWebSocket() { if (m_message) delete m_message; };

	int GetVersion() { return m_version; }
	WebSocketState GetState() { return m_state; }
	void SetState(WebSocketState States) { m_state = States; }

	virtual bool Handshake(const char* data, size_t length, std::string &response) = 0;
	virtual const CWebSocketMessage* Handle(const char* &buffer, size_t &length, bool &send);
	virtual const CWebSocketMessage* Send(WebSocketFrameOpcode opcode, const char* data = NULL, uint32_t length = 0);
	virtual const CWebSocketFrame* Ping(const char* data = NULL) const = 0;
	virtual const CWebSocketFrame* Pong(const char* data = NULL) const = 0;
	virtual const CWebSocketFrame* Close(WebSocketCloseReason reason = WebSocketCloseNormal, const std::string &message = "") = 0;
	virtual void Fail() = 0;

protected:
	int m_version;
	WebSocketState m_state;
	CWebSocketMessage *m_message;

	virtual CWebSocketFrame* GetFrame(const char* data, uint64_t length) = 0;
	virtual CWebSocketFrame* GetFrame(WebSocketFrameOpcode opcode, const char* data = NULL, uint32_t length = 0, bool final = true, bool masked = false, int32_t mask = 0, int8_t extension = 0) = 0;
	virtual CWebSocketMessage* GetMessage() = 0;
};
