#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	char g[102][102];
	int f[102][102];
	
	int casei=1;
	
	while(cin>>n>>m,m||n){//n,m
		for(int i=0;i<n;i++){
			cin>>g[i];
		}
/*		cout<<endl<<endl;
		for(int i=0;i<n;i++){
			cout<<g[i]<<endl;
		}*/
		memset(f,'0',sizeof(f));
		
		for(int row=0;row<n;row++){
			for(int col=0;col<m;col++){
				if(g[row][col]=='*'){
					for(int trow=-1;trow<2;trow++){
						if(row+trow<0||row+trow>n)continue;
						for(int tcol=-1;tcol<2;tcol++){
							if(tcol==0&&trow==0){
								f[row][col]='*';
								continue;
							}
							if(col+tcol<0||col+tcol>m)continue;
							if(g[row+trow][col+tcol]=='.'){
								f[row+trow][col+tcol]++;
							}
						}
					}
				}
			}
		}
		if(casei>1)printf("\n");
		printf("Field #%d:\n",casei++);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%c",f[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
