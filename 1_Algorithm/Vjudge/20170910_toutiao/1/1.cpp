#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=3e5+10;

vector<int> G[MAXN];
int N,Q,w[MAXN];
map<int,int> mp;



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    int cnt=1;
    for(int i=1;i<=N;i++){
        cin>>w[i];
        if(mp.find(w[i])==mp.end()){
            mp[w[i]]=cnt++;
        }
        G[mp[w[i]]].push_back(i);
    }
    /*
    for(int i=1;i<=cnt;i++){
        sort(G[i].begin(),G[i].end());
    }*/
    cin>>Q;
    for(int qi=0;qi<Q;qi++){
         int l,r,k;
         cin>>l>>r>>k;
         if(mp.find(k)==mp.end()){
             cout<<0<<endl;
             continue;
         }
         k=mp[k];
         int lpos=0,rpos=G[k].size()-1;
         if(G[k][0]>r||G[k][rpos]<l){
             cout<<0<<endl;
             continue;
         }
         while(lpos<=rpos){
             int mid=(lpos+rpos)/2;
             if(G[k][mid]>=l){
                  rpos=mid-1;
             }else{
                 lpos=mid+1;
             }
         }
         int _l=lpos;
         lpos=0,rpos=G[k].size()-1;
         while(lpos<=rpos){
             int mid=(lpos+rpos)/2;
             if(G[k][mid]>r){
                  rpos=mid-1;
             }else{
                 lpos=mid+1;
             }
         }
         int _r=rpos;
         if(_r<_l){
             cout<<0<<endl;
         }
         cout<<_r-_l+1<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
