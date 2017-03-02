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
const int MAXN=1e5+10;

int d[MAXN],a[MAXN];
int N,M;
bool vis[MAXN];

bool Check(int ed){
    memset(vis,false,sizeof(vis));
    long long int sum=0;
    int cnt=0;
    for(int i=ed;i;i--){
        if((d[i]!=0)&&(!vis[d[i]])){
            vis[d[i]]=true;
            cnt++;
            sum+=a[d[i]];
        }else if(sum>0){
            sum--;
        }
    }
    if(sum==0 && cnt==M){
         return true;
    }else
        return false;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>d[i];
    }
    for(int i=1;i<=M;i++){
        cin>>a[i];
    }
    if(!Check(N)){
        return 0*puts("-1");
    }
    int l=0,r=N;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(Check(mid)){
             r=mid;
        }else{
            l=mid;
        }
    }
    printf("%d\n",r);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
