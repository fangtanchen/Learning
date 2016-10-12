#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX_SIZE 102

class CState{
	public:
		int s;
		int n;
		int m;
		int t;
		CState(int a,int b,int c,int d){
			s=a;
			n=b;
			m=c;
			t=d;
		}
		CState(const CState &p){
			s=p.s;
			n=p.n;
			m=p.m;
			t=p.t;
		}
		CState(){
			s=n=m=t=0;
		}
}; 

int S,N,M,goal;
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE/2];
/*
bool Check(int a,int b,int c){
	return ((a>=0)&&(a<=S)&&(b>=0)
		  &&(b<=N)&&(c>=0)&&(c<=M));
}*/

bool Check(const CState &pos){
	return ((pos.s>=0)&&(pos.s<=S)&&(pos.n>=0)
		  &&(pos.n<=N)&&(pos.m>=0)&&(pos.m<=M));
}
bool Satisfy(const CState &pos){
	int temp=S/2;
	int res=((pos.s==temp)+(pos.n==temp)+(pos.m==temp));
	return (res>=2);
}

int BFS(){
	CState st(S,0,0,0);
	vector<CState> qe;
	qe.push_back(st);

	int qi=0;
	while(qi<(int)qe.size()){
		CState np(qe[qi]);
		CState tp;
		tp.t=np.t+1;
		//move s to n,m
		if(np.s>0){
			if(np.s+np.n>N){
				tp.s=np.s+np.n-N;
				tp.n=N;
				tp.m=np.m;
			}else{
				tp.s=0;
				tp.n=np.s+np.n;
				tp.m=np.m;
			}
			if((!visited[tp.s][tp.n][tp.m])){
				visited[tp.s][tp.n][tp.m]=true;
				qe.push_back(tp);
				if(Satisfy(tp)){
					return tp.t;
				}
			}
			
			if(np.s+np.m>=M){
				tp.s=np.s+np.m-M;
				tp.m=M;
				tp.n=np.n;
			}else{
				tp.s=0;
				tp.m=np.s+np.m;
				tp.n=np.n;
			}
			if(!visited[tp.s][tp.n][tp.m]){
				visited[tp.s][tp.n][tp.m]=true;
				qe.push_back(tp);
				if(Satisfy(tp)){
					return tp.t;
				}
			}

		}
		
		//move n to s,m
		if(np.n>0){
			if(np.n+np.s>S){
				tp.s=S;
				tp.n=np.s+np.n-S;
				tp.m=np.m;
			}else{
				tp.s=np.s+np.n;
				tp.n=0;
				tp.m=np.m;
			}
			if((!visited[tp.s][tp.n][tp.m])){
				visited[tp.s][tp.n][tp.m]=true;
				qe.push_back(tp);
				if(Satisfy(tp)){
					return tp.t;
				}
			}
			
			if(np.n+np.m>M){
				tp.s=np.s;
				tp.n=np.n+np.m-M;
				tp.m=M;
			}else{
				tp.s=np.s;
				tp.n=0;
				tp.m=np.n+np.m;
			}
			if(!visited[tp.s][tp.n][tp.m]){
				visited[tp.s][tp.n][tp.m]=true;
				qe.push_back(tp);
				if(Satisfy(tp)){
					return tp.t;
				}
			}

		}
		
		//move m to s,n
		if(np.m>0){
			if(np.m+np.s>S){
				tp.s=S;
				tp.n=np.n;
				tp.m=np.s+np.m-S;
			}else{
				tp.s=np.s+np.m;
				tp.n=np.n;
				tp.m=0;
			}
			if((!visited[tp.s][tp.n][tp.m])){
				visited[tp.s][tp.n][tp.m]=true;
				qe.push_back(tp);
				if(Satisfy(tp)){
					return tp.t;
				}
			}
			
			if(np.m+np.n>N){
				tp.s=np.s;
				tp.m=np.m+np.n-N;
				tp.n=N;
			}else{
				tp.s=np.s;
				tp.m=0;
				tp.n=np.n+np.m;
			}
			if(!visited[tp.s][tp.n][tp.m]){
				visited[tp.s][tp.n][tp.m]=true;
				qe.push_back(tp);
				if(Satisfy(tp)){
					return tp.t;
				}
			}

		}
		qi++;
	}

	return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d%d",&S,&N,&M),S||N||M){
		if(S%2){
			printf("NO\n");
			continue;
		}
		
		if(M>N){
			int temp=M;
			M=N;
			N=temp;
		}
		memset(visited,false,sizeof(visited));
		goal=S/2;
		int res=BFS();
		if(res<0){
			printf("NO\n");
		}else{
			printf("%d\n",res);
		}

	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
