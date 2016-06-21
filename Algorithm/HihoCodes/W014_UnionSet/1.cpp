#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<map>
#include<string>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXN 100010

map<string,string> fa;
map<string,string>::iterator it;
int N;

string Find(string x){
    string fx=fa[x];
    if(x==fx)return x;
    string root=Find(fx);
    fa[x]=root;
    return root;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    string name[2];
    int op;
    for(int i=0;i<N;i++){
        cin>>op>>name[0]>>name[1];
        for(int pi=0;pi<2;pi++){
            if(fa[name[pi]].empty()){
                 fa[name[pi]]=name[pi];
            }
        }
        if(op==0){
            fa[Find(name[0])]=Find(name[1]);
        }else{
            if(Find(name[0])==Find(name[1]))puts("yes");
            else puts("no");
        }

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
