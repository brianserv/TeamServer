#include "FlashPolicyService.h"
#if defined (_WIN32) || defined (_WIN64)
#include "mdump.h"
#else
#endif

int main(int argc, char* argv[])
{
#if defined (_WIN32) || defined (_WIN64)
	MiniDumper dump(NULL, "TeamFlashPolicy Server Dump");
#else
#endif

	cout << "               ★★★★★★★★★★★★★★★★★★★★★★★★★" << endl;
	cout << "               ★                                              ★" << endl;
	cout << "               ★      TeamFlashPolicy Server                  ★" << endl;
	cout << "               ★       Copyright (c) 2015,21Pink              ★" << endl;
	cout << "               ★             All rights reserved.             ★" << endl;
	cout << "               ★                                              ★" << endl;
	cout << "               ★★★★★★★★★★★★★★★★★★★★★★★★★\n\n\n" << endl;

	CFlashPolicyService FlashPolicyService("TeamFlashPolicy Server", "FlashPolicyServer");
	FlashPolicyService.RegisterService(argc, argv);

	return 0;
}