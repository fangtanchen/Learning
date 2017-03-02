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

int cnt1,cnt2;
int N;
int a[MAXN];
vector<pii > G;
int pos1[MAXN],pos2[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    for(int ni=1;ni<=N;ni++){
        cin>>a[ni];
        if(a[ni]==1){
            cnt1++;
            pos1[cnt1]=ni;
        }else{
            cnt2++;
            pos2[cnt2]=ni;
        }
    }
    for(int i=1;i<=2*N;i++){
        if(pos1[i]==0){
            pos1[i]=N+1;
        }
        if(pos2[i]==0){
            pos2[i]=N+1;
        }
    }
    for(int t=1;t<=N;t++){
        int winner=0,w1=0,w2=0,i1=0,i2=0;
        int j=0;
        while(j<N){
            if(pos1[i1+t]<pos2[i2+t]){
                w1++;
                winner=w1;
                j=pos1[i1+t];
                i1+=t;
                i2=j-i1;
            }else{
                w2++;
                winner=w2;
                j=pos2[i2+t];
                i2+=t;
                i1=j-i2;
            }
        }
        if((j==N)&&(w1!=w2)&&(max(w1,w2)==winner)){
            G.push_back(make_pair(winner,t));
        }
    }
    sort(G.begin(),G.end());
    printf("%d\n",G.size());
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
