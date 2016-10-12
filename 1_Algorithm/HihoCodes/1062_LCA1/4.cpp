#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<string>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=110;
int N,M;
map<string,string> fa;
map<string,int> vis;



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    string name[2];
    for(int i=0;i<N;i++){
        cin>>name[0]>>name[1];
        fa[name[1]]=name[0];
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        vis.clear();
        cin>>name[0]>>name[1];

        string tmp;
        tmp=name[0];
        while(!tmp.empty()){
            vis[tmp] =1;
            tmp=fa[tmp];
        }
        tmp=name[1];
        bool flag=true;
        while(!tmp.empty()){
            if(vis[tmp]==1){
                cout<<tmp<<endl;
                flag=false;
                break;
            }
            tmp=fa[tmp];
        }
        if(flag)cout<<-1<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
