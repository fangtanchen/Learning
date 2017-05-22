#include<iostream>
#include<bitset>
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
const int MAXN=3e4+10;

bitset<MAXN> mask[MAXN][5];
int id[MAXN];
int x[5][MAXN];
int N;

int globalj;


bool cmp(int a,int b){
    return x[globalj][a]<x[globalj][b];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    for(int ni=1;ni<=N;ni++){
        for(int j=0;j<5;j++){
            cin>>x[j][ni];
        }
        id[ni]=ni;
    }
    for(int j=0;j<5;j++){
        globalj=j;
        sort(id+1,id+N+1,cmp);

        bitset<MAXN> tmpmask;
        for(int i=1;i<=N;i++){
            mask[id[i]][j]=tmpmask;
            tmpmask[id[i]]=1;
        }
    }
    for(int i=1;i<=N;i++){
        bitset<MAXN> ans=mask[i][0];
        for(int j=1;j<5;j++){
            ans=ans&mask[i][j];
        }
        cout<<ans.count()<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
