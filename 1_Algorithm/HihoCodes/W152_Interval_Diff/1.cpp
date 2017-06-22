#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
int A[4*MAXN],flag[4*MAXN];
int id[4*MAXN];
int N,M;
int cntA,cntB;


bool Cmp(int x,int y){
    return A[x]<A[y];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    for(int i=0;i<2*N;i+=2){
        scanf("%d%d",A+i,A+i+1);
        flag[i]=1;flag[i+1]=2;
    }
    for(int i=0,j=2*N;i<2*M;i+=2,j+=2){
        scanf("%d%d",A+j,A+j+1);
        flag[j]=3;flag[j+1]=4;
    }
    for(int i=2*N+2*M-1;i>=0;i--)id[i]=i;
    cntA=cntB=0;
    sort(id,id+2*N+2*M,Cmp);
    int imax=2*N+2*M;
    int ans=0;
    int l=A[0],r=A[0];
    for(int i=0;i<imax;i++){
        if(cntA&&(!cntB))ans+=A[id[i]]-A[id[i-1]];
        switch(flag[id[i]]){
            case 1:
                cntA++;
                break;
            case 2:
                cntA--;
                break;
            case 3:
                cntB++;
                break;
            case 4:
                cntB--;
                break;
        }
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
