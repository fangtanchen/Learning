#include<iostream>
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
const int MAXN=1005;

bool vis[MAXN];
char str[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(vis,false,sizeof(vis));
    scanf("%s",str);
    vis['a'-1]=true;;
    bool flag=true;
    for(int i=0;str[i];i++){
        if(!vis[str[i]]){
            if(vis[str[i]-1]){
                vis[str[i]]=true;
            }else{
                flag=false;
                 break;
            }
        }
    }
    if(flag)puts("YES");
    else puts("NO");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
