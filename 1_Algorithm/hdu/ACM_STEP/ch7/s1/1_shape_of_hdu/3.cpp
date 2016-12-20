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
const int MAXN=1e5+10;

typedef pair<int,int> pii;

pii pt[MAXN];
pii st[MAXN];
int stlen;

int Direction(pii p0,pii p1,pii p2){
    return (p2.first-p0.first)*(p1.second-p0.second)
        -(p2.second-p0.second)*(p1.first-p0.first);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    while(scanf("%d",&n),n!=0){
        stlen=0;
        for(int ni=0;ni<n;ni++){
            scanf("%d%d",&pt[ni].first,&pt[ni].second);
        }
        bool flag=true;
        for(int ni=0;ni<n;ni++){
             int i=ni,j=(ni+1)%n,k=(ni+2)%n;
             if(Direction(pt[i],pt[j],pt[k])>=0){
                 flag=false;
                 break;
             }
        }
        if(flag){
             printf("convex\n");
        }else{
             printf("concave\n");
        }

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
