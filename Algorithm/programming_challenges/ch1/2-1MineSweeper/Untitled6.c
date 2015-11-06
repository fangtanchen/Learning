#include<stdio.h>
#include<string.h>

int main(){
	int n,m,i,j,num=0,k,l;
	int s[105][105],ch;
	while(scanf("%d%d",&n,&m)&&(n||m)){
		getchar();
		if(num)printf("\n");
		
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				ch=getchar();
				if(ch=='*'){
					s[i][j]=-100;
					for(k=-1;k<2;k++){
						for(l=-1;l<2;l++){
							s[i+k][j+l]++;
						}
					}
				}
			}
			getchar();
		}
		printf("Field #%d:\n",++num);
		for(i=1;i<=n;i++){
			
			for(j=1;j<=m;j++){
				if(s[i][j]<0)printf("*");
				else printf("%d",s[i][j]);
			}
			printf("\n");
		}
	}
		
	return 0;
}
