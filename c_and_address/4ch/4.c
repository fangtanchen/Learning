#include<stdio.h>

void copy_n(char dst[], char src[], int n){
	int dst_i=0;
	int src_i=0;
	for(dst_i=0;dst_i<n;dst_i++){
		dst[dst_i]=src[src_i];
		if(src[src_i]!=0)
			src_i++;
	}
}

int main(){
	char s1[25]="fdadfafdaf";
	char s2[25]="reqtfrtwfgsdgsfgs";
	char s3[25]="iojkmkljijiojlk";
	copy_n(s1, s2, 15);
	printf("%s\n%s\n", s1, s2);
	copy_n(s3, s1, 15);
	printf("%s\n%s\n", s1, s2);
	
	return 0;
}
