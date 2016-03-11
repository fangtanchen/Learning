#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

long long N, Q;
long long P[100010];
priority_queue< long long > qe; 

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%ld%ld", &N, &Q)){
		for(int i=1;i<=N;i++){
			scanf("%ld", &P[i]);
		}
		int ans=0;
		{//deal with k=N
			while(!qe.empty()){
				qe.pop();
			}
			for(int i=1;i<=N;i++){
				qe.push(P[i])	;
			}
			long long  sum=0;
			for(int i=1;i<=N;i++){
				sum+=(i*qe.top());
				qe.pop();
			}
			if(sum<=Q){
				ans=N;
			}
			else{
				printf("-1\n");
				continue;
			}
		}
		for(int K=1;K<N;K++){
			while(!qe.empty()){
				qe.pop();
			}
			for(int i=1;i<=K;i++){
				qe.push(P[i])	;
			}
			long long sum=0;
			for(int i=K+1;i<=N;i++){
				sum=sum+(i-K)*qe.top();
				qe.pop();
				qe.push(P[i]);
			}
			for(int i=N-K+1;i<=N;i++){
				sum=sum+(i)*qe.top();
				qe.pop();
			}
			if(sum<=Q){
				ans=K;
				break;
			}
		}
		printf("%d\n", ans);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
