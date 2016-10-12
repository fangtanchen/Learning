#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *dirp;

	if(2!=argc)
		err_quit("a single argument is required");
	if((dp=opendir(argv[1]))== NULL){
		err_sys("can't open %s", argv[1]);
	}
	while(NULL!=(dirp=readdir(dp))){
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	exit(0);
}

