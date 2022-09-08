#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
int main(){
	int sockfd;
	char str[100];
	struct sockaddr_in servaddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(22000);
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sockfd,(struct sockaddr *) &servaddr,sizeof(servaddr));
	while(1){
		bzero( str, 100);
		printf("Enter Message- \n");
		fgets(str,100,stdin);
		send(sockfd,str,strlen(str),0);
		bzero( str, 100);
		recv(sockfd,str,100,0);
		printf("From S-C %s\n",str);
	}
}
