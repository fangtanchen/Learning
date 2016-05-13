#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int n;
	
	while(EOF!=scanf("%d",&n)){		
		
		int f[4][600];
		int len[4]={1,1,1,1};
		
		memset(f,0,sizeof(f));
		
		for(int i=0;i<4;i++){
			f[i][0]=1;
		}
		
		for(int ni=5;ni<=n;ni++){
			int fdi=ni%4;
			int fdlen=0;
			int max=0;
			for(int i=0;i<5;i++){
				if(max<len[i]){
					max=len[i];
				}
			}
			
			len[fdi]=0;
			
			int c=0;
			int imax=max;
			for(int i=0;i<4;i++){
				if(i==fdi){
					continue;
				}
				
				int templen=0;
				for(int j=0;j<len[i];j++){
					int temp=c+f[i][j]+f[fdi][j];
					f[fdi][j]=temp%10000;
					c=temp/10000;
					templen++;
				}
				while(c){
					int temp=c+f[fdi][templen];
					f[fdi][templen]=temp%10000;
					c=temp/10000;
					templen++;
				}
				if(len[fdi]<templen){
					len[fdi]=templen;
				}
			}		
		}
		int fdi=n%4;
		printf("%d",f[fdi][len[fdi]-1]);
		for(int i=len[fdi]-2;i>=0;i--){
			printf("%04d",f[fdi][i]);
		}
		printf("\n");
	}
	
	
	
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
