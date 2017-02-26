#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=2e5+10;

char p[MAXN],t[MAXN];
int plen,tlen;
int A[MAXN];
map<int,int> mp;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    t[0]=p[0]=1;
    scanf("%s",t+1);
    scanf("%s",p+1);
    plen=strlen(p+1);
    tlen=strlen(t+1);
    for(int i=1;i<=tlen;i++){
         scanf("%d",A+i);
         mp[A[i]]=i;
    }
    int l=0,r=tlen;
    while(l+1<r){
        int mid=(l+r)/2;
        int pi,ti;
        for(pi=1,ti=1;pi<=plen&&ti<=tlen;ti++){
             if(mp[ti]<=mid)continue;
             if(p[pi]==t[ti]){
                 pi++;
             }
        }
        if(pi>plen)l=mid;
        else r=mid;
    }
    printf("%d\n",l);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
