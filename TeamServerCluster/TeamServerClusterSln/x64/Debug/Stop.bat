@echo off
taskkill /f /t /im TeamWebBackendServer.exe
taskkill /f /t /im TeamWebSocketServer.exe 
taskkill /f /t /im TeamFlashPolicyServer.exe
taskkill /f /t /im TeamCenterServer.exe  
taskkill /f /t /im TeamDBServer.exe      
taskkill /f /t /im TeamDLServer.exe   
taskkill /f /t /im TeamGameServer.exe 
taskkill /f /t /im TeamGateServer.exe      
exit