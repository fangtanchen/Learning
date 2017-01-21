#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
typedef pair<int,int> pii;


pii pos[30],neg[30];
int pos_cnt,neg_cnt;

bool cmp1(pii x,pii y){
    return x.first<=y.first;
}
bool cmp2(pii x,pii y){
    return x.first>=y.first;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T,N;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
         scanf("%d",&N);
         pos_cnt=0;
         neg_cnt=0;
         for(int i=0;i<N;i++){
              int v,c;
              scanf("%d%d",&v,&c);
              if(v>=0){
                  pos[pos_cnt].first=v;
                  pos[pos_cnt++].second=c;
              }else{
                  neg[neg_cnt].first=v;
                  neg[neg_cnt++].second=c;
              }
         }
         sort(pos,pos+pos_cnt,cmp1);
         sort(neg,neg+neg_cnt,cmp2);
         int sum=0;
         int ans=0;
         int pnum=0;
         for(int pi=0;pi<pos_cnt;pi++){
             int v=pos[pi].first,c=pos[pi].second;
             ans+=(pnum+1+pnum+c)*c/2*v;
             sum+=c*v;
             pnum+=c;
         }
         bool flag=false;
         for(int pi=0;pi<neg_cnt;pi++){
             if(flag)break;
             int v=neg[pi].first,c=neg[pi].second;
             for(int ci=1;ci<=c;ci++){
                 sum+=v;
                 if(sum<=0){
                     flag=true;
                      break;
                 }
                 ans=ans+sum;
             }
         }
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
