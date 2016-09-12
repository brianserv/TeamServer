 #!/bin/sh
 
/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamFlashPolicyServer -d > TeamFlashPolicyServer.log 2>&1 & 

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamDBServer -d > TeamDBServer.log 2>&1 &

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamDLServer -d > TeamDLServer.log 2>&1 &

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamCenterServer -d > TeamCenterServer.log 2>&1 &

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamGameServer -d > TeamGameServer.log 2>&1 &

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamGateServer -d > TeamGateServer.log 2>&1 &

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamWebBackendServer -d > TeamWebBackendServer.log 2>&1 &

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamHallServer -d > TeamHallServer.log 2>&1 &

/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamWebsocketServer -d > TeamWebsocketServer.log 2>&1 &









 

 
 





 
 
