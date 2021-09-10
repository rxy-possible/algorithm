#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<ctype.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define SERV_PORT 9527

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc,char *argv[])
{
	int lfd = 0,cfd = 0;
	
	int ret;
	
	char buf[BUFSIZ],client_IP[BUFSIZ];
	
	struct sockaddr_in serv_addr,client_addr;                                 //定义服务器地址结构 和 客户端地址结构
	
	socklen_t client_addr_len;                                                //客户端地址结构大小
	
	serv_addr.sin_family = AF_INET;                                           //IPv4

	serv_addr.sin_port = htons(SERV_PORT);                                    //转为网络字节序的 端口号
	
	//serv_addr_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);                            //获取本机任意有效IP
	
	lfd = socket(AF_INET,SOCK_STREAM,0);                                      //第一個參數 domain 協議 指定IPv4,第二个参数是有保障的（即能保证数据正确传送到对方）面向连接的SOCKET，多用于资料（如文件）传送
	                                                                          //第三个参数 对于protocol为0（IPPROTO_IP)的raw socket。用于接收任何的IP数据包。其中的校验和和协议分析由程序自己完成
	if(lfd == -1)
	{
		sys_err("socket error");  //如果返回负1,结束程序
	}
	
	bind(lfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));                //给服务器socket绑定地址结构（IP+port)
	
	listen(lfd,128);                                                          //监听socket（设置监听上限）                                
	
    client_addr_len = sizeof(client_addr);                                    //获取客户端地址结构大小    
	
	//cfd = accept(lfd,(struct sockaddr *)client_addr,&client_addr_len);
	cfd = accept(lfd, (struct sockaddr *)&client_addr, &client_addr_len);     //阻塞，去等待客户端连接请求，接收到客户端请求之后，进行下面的操作
	
	if(cfd == -1)
	{
		sys_err("accept error");
	}
	
	printf("client ip:%s port:%d\n",
		   inet_ntop(AF_INET,&client_addr.sin_addr.s_addr,client_IP,sizeof(client_IP)),
		   ntohs(client_addr.sin_port));
	
	while(1)
	{
		ret = read(cfd,buf,sizeof(buf));                                      // 读客户端数据
	
	    write(STDOUT_FILENO,buf,ret);                                         //写到屏幕查看
	
	    for(int i = 0; i < ret;i++)
 	    {
			buf[i] = toupper(buf[i]);                                         //小写 -- 大写
	    }
	
	    write(cfd,buf,ret);                                                   //将大写，写回给客户端
	}
	
	close(lfd);
	close(cfd);
	
	return 0;
		
}