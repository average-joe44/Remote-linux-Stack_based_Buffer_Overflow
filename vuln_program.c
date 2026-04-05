#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(){
	int server_fd, client_fd;
	struct sockaddr_in addr;
	char buffer[64];
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0){
		perror("socket");
		exit(1);
	}
	
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4444);
	addr.sin_addr.s_addr = INADDR_ANY;
	
	bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
	listen(server_fd, 5);
	
	printf("Listening on port 4444");
	
	client_fd = accept(server_fd, NULL, NULL);
	
	printf("Connection received");
	
	read(client_fd, buffer, 512);
	
	close(client_fd);
	close(server_fd);
}
