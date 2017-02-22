#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef long long int LL;
const int MAXN=1e5+10;


struct node{
    int a1,a2,b1,b2;
    int tag;
};

bool operator<(const node &x,const node &y){
    return x.a1+x.b1<y.a1+y.b1;
}



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n,a1,a2,b1,b2;
    priority_queue<node> Q;
    scanf("%d",&n);
    LL ans=0;
    for(int i=0;i<n;i++){
         scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
         if(a1<=b2&&b1<=a2)continue;
         else if(a1+b1<a2+b2){
             if(a1>b2){
                  ans+=a1-b2;
             }else{
                 ans+=a2-b1;
             }
         }else{
            node tmp;
            tmp.a1=a1;tmp.a2=a2;
            tmp.b1=b1;tmp.b2=b2;
            tmp.tag=1;
            Q.push(tmp);
         }
    }
    int cnt=0;
    while(!Q.empty()){
        cnt++;
         node tmp=Q.top();
         Q.pop();
         if(cnt&1){
              ans+=tmp.a1;
         }else{
             ans-=tmp.b1;
         }

         if(tmp.tag==1){
              tmp.tag=2;
              tmp.a1=tmp.a2;
              tmp.b1=tmp.b2;
              tmp.a2=0;
              tmp.b2=0;
              Q.push(tmp);
         }
    }
    printf("%lld\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
