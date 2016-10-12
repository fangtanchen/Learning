#include<stdio.h>
#include<string.h>
#define SIZE 1000
int xlen;
int zlen;
char X[SIZE];
char Z[SIZE];

int main(int argc,char** argv){
	
	while(1){
		scanf("%s %s",X,Z);
		xlen=strlen(X);
		zlen=strlen(Z);
		int ans=dfs(0,0);
		printf("%d\n",ans);
	}

	return 0;
}


int max(int a,int b){
	return a>b?a:b;
}

int dfs(int xi,int zi){
	if(xi>=xlen||zi>=zlen)return 0;
	if(X[xi]==Z[zi]){
		return 1+dfs(xi+1,zi+1);
	}
	else{
		return max(dfs(xi+1,zi),dfs(xi,zi+1));	
	}
}

