环回地址:
    数据将通过回环接口（loopback interface）发送和接收。回环接口是计算机内部的虚拟网络接口，用于在同一台计算机上的进程之间进行通信。
前置条件:
    在本地搭建c/s
    套接字绑定该主机IP(分配到的IP) 可以与外网通讯
    环回地址只是用于本地进程通讯
    

ARP 通过MAC找到所对应的IP
套接字：保存了进程所需网络的状态和数据结构，为应用程序提供了API进行网络通讯，对套接字操作时触发系统调用，操作系统进行网络通讯