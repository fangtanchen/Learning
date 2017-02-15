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
const int MAXN=1e6+10;

int st[300],ed[300];
char str[MAXN];
char x,y;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        memset(st,-1,sizeof(st));
        memset(ed,-1,sizeof(ed));
    scanf("%s",str);
    for(int i=0;str[i];i++){
        if(st[str[i]]==-1){
            st[str[i]]=i;
        }
        ed[str[i]]=i;
    }
    int Q;
    scanf("%d",&Q);
    while(Q--){
        scanf("\n%c %c",&x,&y);
        if((st[x]!=-1)&&(ed[y]!=-1)&&(st[x]<ed[y]))puts("YA");
        else puts("TIDAK");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
