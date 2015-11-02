#include<stdio.h>
#include<stdlib.h>

int main(){
	char ch;
	int n_braces=0;
	while(EOF!=(ch=getchar())){
		if('{'==ch){
			n_braces+=1;
		}
		if('}'==ch){
			if(0==n_braces){
				printf("error: more right brace\n");
			}
			else{
				n_braces-=1;
			}
		}
		//if('\n'==ch)break;
	}
	if(n_braces>0)
			printf("%d unmatched opening braces(s)!\n", n_braces);
	printf("ffdadfafd\n");
	return EXIT_SUCCESS;
}
