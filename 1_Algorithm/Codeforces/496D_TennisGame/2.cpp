#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef pair<int,int> pii;
const int MAXN=2e5+10;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;


int a[MAXN],pos1[MAXN],pos2[MAXN];
int cnt1,cnt2;
vector<pii > G;
int N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    cnt1=cnt2=0;
    for(int ni=1;ni<=N;ni++){
        cin>>a[ni];
        if(1==a[ni]){
            cnt1++;
            pos1[cnt1]=ni;
        }else{
             cnt2++;
             pos2[cnt2]=ni;
        }
    }
    for(int ni=1;ni<=2*N;ni++){
         if(pos1[ni]==0)pos1[ni]=N+1;
         if(pos2[ni]==0)pos2[ni]=N+1;
    }
    for(int t=1;t<=N;t++){
        int j,win,w1,w2,p1,p2;
        j=win=w1=w2=p1=p2=0;
        while(j<N){
            if(pos1[p1+t]<pos2[p2+t]){
                w1++;
                win=w1;
                j=pos1[p1+t];
                p1=p1+t;
                p2=j-p1;
            }else{
                 w2++;
                 win=w2;
                 j=pos2[p2+t];
                 p2+=t;
                 p1=j-p2;
            }
        }
        if((N==j)&&(w1!=w2)&&(max(w1,w2)==win)){
             G.push_back(make_pair(win,t));
        }
    }
    sort(G.begin(),G.end());
    printf("%d\n",(int)G.size());
    for(int i=0;i<G.size();i++){
        printf("%d %d\n",G[i].first,G[i].second);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
