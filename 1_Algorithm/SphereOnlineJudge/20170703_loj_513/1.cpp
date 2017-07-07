#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;

int N,M;
int A[MAXN];
int ans=2147483647;

map<int,set<int> > mp;

void Insert(int x,int p){
    set<int>::iterator it=mp[x].lower_bound(p);
    if(it!=mp[x].end())ans=min(ans,*it-p);
    if(it!=mp[x].begin())ans=min(ans,p-*(--it));
    mp[x].insert(p);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>A[i];
        Insert(A[i],i);
    }
    while(M--){
         int x,y;
         cin>>x>>y;
         if(x!=y){
             if(mp[x].size()>mp[y].size()){
                 swap(mp[x],mp[y]);
             }
             {
                 for(set<int>::iterator it=mp[x].begin();
                         it!=mp[x].end();it++)
                     Insert(y,*it);
             }
             mp[x].clear();
         }
         cout<<ans<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
