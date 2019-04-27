#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t ret;
	int fd;
	ret = fork();

	if(ret < 0){
		perror("fork error");
		exit(1);
	}
	else if(ret == 0){
		//child
		setsid();
		chdir("/");
		umask(0);

		for(fd = 0; fd < getdtablesize(); fd++){
			close(fd);
		}
		while(1){
			sleep(1);
			printf("=============\n");
		}
	}
	else{
		//parent
		printf("parent process\n");
		exit(0);
	}
	return 0;
}
