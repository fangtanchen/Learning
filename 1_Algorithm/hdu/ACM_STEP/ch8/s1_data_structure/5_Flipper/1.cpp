#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<utility>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=110;

typedef pair<int,int> pii;
vector<pii> S[MAXN];
int N;
char cards[MAXN],cmd[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        int casi=1;
        while(EOF!=scanf("%d",&N),N){
            printf("Pile %d\n",casi++);
             scanf("%s%s",cards+1,cmd+1);
             for(int i=1;i<=N;i++){
                 S[i].clear();
                 S[i].push_back(make_pair(i,cards[i]=='U'));
             }
             int st=1,ed=N,pi=1;
             while(st<ed){
                 if(cmd[pi]=='L'){
                     int ti=st;
                     st++;
                     for(int i=S[ti].size()-1;i>=0;i--){
                         S[st].push_back(make_pair(S[ti][i].first,1-S[ti][i].second));
                     }
                 }else{
                     int ti=ed;
                     ed--;
                     for(int i=S[ti].size()-1;i>=0;i--){
                         S[ed].push_back(make_pair(S[ti][i].first,1-S[ti][i].second));
                     }
                 }
                 pi++;
             }

             int Q,x;
             scanf("%d",&Q);
             while(Q--){
                 scanf("%d",&x);
                 //for(int cnt=1,i=S[st].size()-1;i>=0;i--,cnt++)
                 {
                     int i=S[st].size()-x;
                     if(S[st][i].second==1)
                         printf("Card %d is a face up %d.\n",x,S[st][i].first);
                     else
                         printf("Card %d is a face down %d.\n",x,S[st][i].first);
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
