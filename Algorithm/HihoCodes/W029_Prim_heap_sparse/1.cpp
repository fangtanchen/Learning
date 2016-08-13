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
#define lson (id<<1)
#define rson ((id<<1)|1)
#define parent (id>>1)

const int MAXN=1e5+10;
const int MAXM=1e6+10;

vector< pair<int,int> > G[MAXN];
pair<int,int> heap[MAXM];
bool vis[MAXN];
int N,M;

void Init(){
    memset(vis,false,sizeof(vis));
}

void PushUp(){
    int id=heap[0].first;
    while(id>1){
        if(heap[id].second>=heap[parent].second)
            break;
        swap(heap[id],heap[parent]);
        id=parent;
    }
}

void PushDown(){
    int id=1;
    int idmax=heap[0].first/2;
    while(id<=idmax){
        int child=lson;
        if(rson<=heap[0].first && (heap[lson].second>heap[rson].second)){
             child=rson;
        }
        if(heap[id].second<=heap[child].second)break;
        swap(heap[id],heap[child]);
        id=child;
    }
}

int PrimSparse(){
    int ans=0;
    int num=0;
    int id=1;
    int len=0;
    do{
        vis[id]=true;
        ans+=len;
        num++;
        if(num==N)break;
        for(int i=G[id].size()-1;i>=0;i--){
            pair<int,int> child=G[id][i];
            if(vis[child.first])continue;
            heap[0].first++;
            heap[heap[0].first]=child;
            PushUp();
        }
        while(vis[heap[1].first]){
            swap(heap[1],heap[heap[0].first]);
            heap[0].first--;
            if(heap[0].first==0)break;
             PushDown();
        }
        if(heap[0].first==0)break;
        id=heap[1].first;
        len=heap[1].second;
        swap(heap[1],heap[heap[0].first]);
        heap[0].first--;
        PushDown();
    }while(1);
    return ans;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    Init();
    for(int mi=1;mi<=M;mi++){
         int i,j,len;
         cin>>i>>j>>len;
         G[i].push_back(make_pair(j,len));
         G[j].push_back(make_pair(i,len));
    }
    cout<<PrimSparse()<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
