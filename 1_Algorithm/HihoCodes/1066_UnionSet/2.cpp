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
const int MAXN=100010;
map<string,string> fa;

string Find(string x){
    string fx=fa[x];
    if(fx==x)return x;
    fa[x]=Find(fx);
    return fa[x];
}
void Union(string x,string y){
     string fx=Find(x);
     string fy=Find(y);
     if(fx==fy)return ;
     fa[fx]=fy;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N;
    scanf("%d",&N);
    int op;
    string name[2];
    for(int i=0;i<N;i++){
        cin>>op>>name[0]>>name[1];
        if(fa[name[0]].empty())fa[name[0]]=name[0];
        if(fa[name[1]].empty())fa[name[1]]=name[1];
        switch(op){
            case 0:
                Union(name[0],name[1]);
                break;
            case 1:
                if(Find(name[0])==Find(name[1])){
                    printf("yes\n");
                }else{
                    printf("no\n");
                }
                break;
        }

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
