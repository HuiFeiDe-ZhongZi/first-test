#include<SOCKET.h>

int main()
{
	// 网络设置与初始化
	struct sockaddr_in serveraddr;
	bzero(&serveraddr,sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	inet_pton(AF_INET,"192.168.209.131",&serveraddr.sin_addr); // 设置服务端ip
	serveraddr.sin_port = htons(8000); // 设置服务端接口

	int clientfd;
	clientfd = SOCKET(AF_INET,SOCK_STREAM,0);

	CONNECT(clientfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));

	printf("client connection server service successly..\n");
	
	// 客户端读取标准输入，发送请求，显示服务端反馈的请求
	
	char buffer[1500];
	bzero(buffer,sizeof(buffer));
	int rsize,wsize;
	while((fgets(buffer,sizeof(buffer),stdin))!=NULL) // stdin 标准输入流
	{
		wsize = send(clientfd,buffer,strlen(buffer),0);
		printf("client send requset success [%s] [%d] \n",buffer,wsize);
		
		rsize = recv(clientfd,buffer,sizeof(buffer),0);
		printf("client recv response success [[%s] [%d]] \n",buffer,rsize);
		bzero(buffer,sizeof(buffer));
	}

	close(clientfd);
	return 0;
}

