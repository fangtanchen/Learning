#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<set>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=31;
const int MAXM=1e5+10;

int sg[MAXN],N;
bool vis[MAXM];
int f[MAXN];
map<int,int> Hash;


int SG(int mask){
    if(Hash.count(mask))return Hash[mask];
    set<int> mex;
    for(int i=0;i<30;i++){
        if(0==((mask>>i)&1)){
            continue;
        }
        int tp=mask;
        for(int j=i;j<30;j+=i+1){
            if(0==((mask>>j)&1))continue;
            tp^=(1<<j);
        }
        mex.insert(SG(tp));
    }
    int ret=0;
    while(mex.count(ret))ret++;
    Hash[mask]=ret;
    return ret;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    /*sg[0]=Hash[0]=0;
    for(int i=1;i<30;i++){
        sg[i]=SG((1<<i)-1);
        cout<<sg[i]<<" ";
    }*/
    cin>>N;
    memset(vis,false,sizeof(vis));
    memset(f,0,sizeof(f));
    int sg[35]={0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
    int ki;
    for(ki=1;ki*ki<=N;ki++){
        ;
    }
    ki--;
    f[1]=N-ki+1;
    int mx=1;
    for(int i=2;i<=ki;i++){
        if(vis[i])continue;
        int lim=N/i,cur=1,cnt=0;
        for(;cur<=lim;){
            cnt++;
            cur*=i;
            if(cur>ki)f[1]--;
            else vis[cur]=true;
        }
        ++f[cnt];
        if(mx<cnt)mx=cnt;
    }
    int ans=0;
    for(int i=1;i<=mx;i++){
        if(1&f[i]){
            ans^=(sg[i]);
        }
    }
    if(ans)puts("Vasya");
    else puts("Petya");


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
