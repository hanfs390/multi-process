#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t ret;
   
    /*
     * 执行代码
     */
	ret = fork();

	if(ret < 0){
		perror("fork error");
		return -1;
	}
	else if(ret == 0){
		/* 子进程的执行代码 */
		printf("In the child, child id = %d  parent id = %d\n", getpid(), getppid());

		while(1)
		;
	}
	else{
		/* 父进程的执行代码 */
		printf("In the parent, child id = %d  parent id = %d\n", ret, getpid());
	}
	return 0;
}
