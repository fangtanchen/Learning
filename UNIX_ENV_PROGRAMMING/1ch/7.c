#include"apue.h"
#include<sys/wait.h>

int main(void){
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");/*print prompt */
	while(fgets(buf, MAXLINE, stdin)!=NULL){
		if('\n'==buf[strlen(buf)-1])
			buf[strlen(buf)-1]=0;//replace newline with null
		if((pid=fork())<0){
			err_sys("fork_error");
		}else if(0==pid){//child
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute:%s", buf);
			exit(127);
		}

		//parent
		if((pid=waitpid(pid, &status, 0))<0)
			err_sys("waitpid error");
		printf("%%");
	}
	exit(0);
}
