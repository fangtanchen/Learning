#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=100010;
const int MAXM=100010;
const int MAXP=200010;
const int SIZE=400010;

map<string,int> s2i;
map<int,string> i2s;
vector<int> G[MAXP];
int num;
int in[MAXP];
int arr[SIZE];
int depth[MAXP];
int last[MAXP];
int arrn;
int N,M;

void Init(){
     s2i.clear();
     i2s.clear();
     memset(in,0,sizeof(in));
     memset(arr,0,sizeof(arr));
     memset(depth,0,sizeof(depth));
     memset(last,0,sizeof(last));
     arrn=1;
     num=1;
     for(int i=1;i<MAXP;i++){
          G[i].clear();
     }
}

void DFS(int node){
    for(int i=G[node].size()-1;i>=0;i--){
        arr[arrn++]=node;
        int child=G[node][i];
        depth[child]=depth[node]+1;
        DFS(child);
    }
    last[node]=arrn;
    arr[arrn++]=node;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        Init();
    scanf("%d",&N);
    string name[2];
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++) {
             cin>>name[j];
             if(s2i[name[j]]==0){
                 s2i[name[j]]=num;
                 i2s[num]=name[j];
                 num++;
             }
        }
        G[s2i[name[0]]].push_back(s2i[name[1]]);
        in[s2i[name[1]]]++;
    }
    for(int i=1;i<num;i++){
        if(0==in[i]){
            depth[i]=1;
            DFS(i);
        }
    }

    scanf("%d",&M);
    for(int i=0;i<M;i++){
        cin>>name[0]>>name[1];
        int k0=last[s2i[name[0]]],k1=last[s2i[name[1]]];
        if(k0>k1)swap(k0,k1);
        int ans=k1;
        for(int i=k0;i<k1;i++){
            if(depth[arr[i]]<depth[arr[ans]])ans=i;
        }
        cout<<i2s[arr[ans]]<<endl;
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
