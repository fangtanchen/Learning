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

char ori[MAXN2];
char par[MAXN1];
int nxt[MAXN1];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int N;
    scanf("%d",&N);
    while(N--){
         scanf("%s%s",par,ori);
         int len=strlen(par);
         nxt[0]=-1;
         for(int i=0,j=-1;i<len;){
             if(j==-1||par[i]==par[j]){
                 nxt[++i]=++j;
             }else{
                 j=nxt[j];
             }
         }

         int ans=0;
         for(int i=0,j=0;ori[i];){
             if(j==-1||ori[i]==par[j]){
                 i++;j++;
             }else{
                 j=nxt[j];
             }
             if(j==len)ans++;
         }
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
