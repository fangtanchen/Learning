#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

const int MAXN=1010;

vector<int> A;
int N;
int id[MAXN];
int kk[MAXN];
int f[MAXN];


int lowbit(int x){
     return x&-x;
}

int Add(int x,int a){
    int tmp=x;
    while(tmp<MAXN){
        f[tmp]+=a;
        tmp+=lowbit(tmp);
    }
    return 0;
}

int Sum(int x){
    int tmp=x;
    int ret=0;
    while(tmp>0){
        ret+=f[tmp];
        tmp-=lowbit(tmp);
    }
    return ret;
}

bool Cmp(int x,int y){
    return A[x]<=A[y];
}

int Solve(vector<int> A,int n){
    for(int i=0;i<n;i++){
        id[i]=i;
    }
    //sort(id,id+n,Cmp);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[id[i]]>A[id[j]]){
                int tmp=id[i];
                id[i]=id[j];
                id[j]=tmp;

            }
        }
    }
    for(int i=0;i<n;i++){
        kk[id[i]]=i+1;
    }
    for(int i=0;i<n-1;i++){
        if(A[id[i]]==A[id[i+1]]){
            kk[id[i+1]]=kk[id[i]];
        }
    }

    memset(f,0,sizeof(f));
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=Sum(kk[i]);
        Add(kk[i],A[i]);
    }
    return ans;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    int ret=Solve(A,N);
    cout<<ret<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
