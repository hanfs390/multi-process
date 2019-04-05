#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t ret;

	ret = fork();

	if(ret < 0){
		perror("fork error");
		exit(1);
	}
	else if(ret == 0){
		//child
		sleep(5);
		printf("In the child process, id = %d\n", getpid());
		exit(0);
	}
	else{
		//parent
		printf("In the parent process, id = %d\n", getpid());
		int status;
		while((ret = waitpid(-1, &status, WNOHANG)) == 0){
			sleep(1);
		}

		if(ret != 0){	
			printf("ret = %d\n", ret);
		}
		while(1)
			;
	}
	return 0;
}
