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
int st[MAXN],ed[MAXN],cnt;
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=0;i<N;i++){
         scanf("%d%d",st+i,ed+i);
    }
    sort(st,st+N);
    sort(ed,ed+N);
    cnt=0;
    int ans=0;
    for(int i=0,j=0;i<N;){
        if(st[i]<ed[j]){
            cnt++;
            i++;
        }else{
            cnt--;
             j++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
