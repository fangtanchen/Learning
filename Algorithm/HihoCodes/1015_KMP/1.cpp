#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAXN1 10010
#define MAXN2 1000010


int N;
char par[MAXN1];
char orig[MAXN2];
int next[MAXN1];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	scanf("%d", &N);
	while(N--){
		scanf("%s", par+1);
		scanf("%s", orig+1);
		memset(next, 0, sizeof(next));
		int q=0;
		for(int i=1;par[i];i++){
			int i1=i+1, q1=q+1;
			{
				while(q){
					if(par[i1]==par[q+1]){
						next[i1]=q+1;
						q++;break;
					}					
					q=next[q];
				}
				if(!q){
					if(par[i1]==par[1]){
						q=1;next[i1]=q;
					}else{
						next[i1]=0;
					}
				}
			}
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
