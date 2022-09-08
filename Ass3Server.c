#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
int main(){
	int listen_fd,comm_fd;
	char str[100];
	int n=0;
	struct sockaddr_in servaddr;
	listen_fd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(22000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(listen_fd,(struct sockaddr *) &servaddr,sizeof(servaddr));
	listen(listen_fd,10);
	comm_fd=accept(listen_fd,(struct sockaddr *) NULL,NULL);
	while(1){
		bzero(str,100);
		recv(comm_fd,str,100,0);
		printf("From C-S %s\n",str);
		bzero(str,100);
		printf("Enter Message- \n");
		fgets(str,100,stdin);
		send(comm_fd,str,sizeof(str),0);
	}
	close(comm_fd);
}
