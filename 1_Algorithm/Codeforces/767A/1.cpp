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
const int MAXN=1e5+10;

//priority_queue<int,vector<int>, greater<int> > q;
priority_queue<int > q;


int a[MAXN],N;



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(!q.empty())q.pop();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",a+i);
    }
    int cnt=N;
    for(int i=0;i<N;i++){
        q.push(a[i]);
        int now=q.top();
        if(now==cnt){
            q.pop();
            cnt--;
            printf("%d",now);
            while((!q.empty())){
                int nex=q.top();
                if(nex!=now-1)break;
                printf(" %d",nex);
                cnt--;
                q.pop();
                now=nex;
            }
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
