#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	pid = fork();

	if(pid < 0){
		perror("fork error");
		return -1;
	}
	else if(pid == 0){
		//child
		sleep(5);
		printf("In the child process, id = %d\n", getpid());
	}
	else{
		//parent
		printf("In the parent process, id = %d\n", getpid());
		int status;
///		pid = wait(&status);//阻塞等待子进程退出，如果子进程状态未改变，wait一直阻塞
		pid = waitpid(-1, &status, 0);
		printf("pid = %d\n", pid);
		while(1)
			;
	}
	return 0;
}
