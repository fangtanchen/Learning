#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<map>
#include<algorithm>
#include<string>


#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


map<string,string> fa;
map<string, int> vis;
int N,M;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        string a,b;
        cin>>a>>b;
        fa[b]=a;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        vis.clear();
         string a,b;
         cin>>a>>b;
         while(!a.empty()){
             vis[a]=1;
             a=fa[a];
         }
         while(!b.empty()){
              if(vis[b])break;
              b=fa[b];
         }
         if(b.empty()){
             cout<<-1<<endl;
         }else{
             cout<<b<<endl;
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
