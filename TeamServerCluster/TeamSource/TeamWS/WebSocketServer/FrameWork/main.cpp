#include "WebSocketService.h"

#if defined (_WIN32) || defined (_WIN64)
#include "mdump.h"
#else
#endif

int main(int argc, char* argv[])
{
#if defined (_WIN32) || defined (_WIN64)
	MiniDumper dump(NULL, "TeamWebSocket Server TDump");
#else
#endif

	cout << "               ★★★★★★★★★★★★★★★★★★★★★★★★★" << endl;
	cout << "               ★                                              ★" << endl;
	cout << "               ★       TeamWebSocket Server                   ★" << endl;
	cout << "               ★       Copyright (c) 2015,21Pink              ★" << endl;
	cout << "               ★             All rights reserved.             ★" << endl;
	cout << "               ★                                              ★" << endl;
	cout << "               ★★★★★★★★★★★★★★★★★★★★★★★★★\n\n\n" << endl;

	CWebSocketService GameService("TeamWebSocketServer", "WebSocketServer");
	GameService.RegisterService(argc, argv);

	return 0;
}