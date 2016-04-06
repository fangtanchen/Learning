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


int calf(int K){
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
				return 1;
			}
			else
				return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%ld%ld", &N, &Q)){
		for(int i=1;i<=N;i++){
			scanf("%ld", &P[i]);
		}
		int lk=1;
		int rk=N;
		if(!calf(rk)){
			printf("-1\n");
			continue;;
		}
		if(calf(lk)){
			printf("%d\n", lk);
			continue;
		}
		while(lk<rk){
			int mid=(lk+rk)/2;
			if(calf(mid)){
				if(!calf(mid-1)){
					printf("%d\n", mid);
					break;
				}
				rk=mid-1;
			}else{
				if(calf(mid+1)){
					printf("%d\n", mid+1);
					break;
				}
				lk=mid+1;
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
