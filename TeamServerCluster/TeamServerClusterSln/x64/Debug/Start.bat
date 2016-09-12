@echo off
echo start TeamBuid ServerGroup Exe
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamFlashPolicyServer.exe " -d
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamCenterServer.exe  " -d
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamDBServer.exe      " -d
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamDLServer.exe   " -d
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamGameServer.exe    " -d
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamGateServer.exe    " -d
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamWebBackendServer.exe " -d
start "" "E:\TeamServerCluster\Bin\Platform\Windows\X64\Debug\TeamWebSocketServer.exe " -d
echo startTeamBuid ServerGroup over
exit