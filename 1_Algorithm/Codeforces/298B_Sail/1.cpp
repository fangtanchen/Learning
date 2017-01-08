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
const int MAXT=1e5+10;
char str[MAXT];
int t,sx,sy,ex,ey;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d%d%d",&t,&sx,&sy,&ex,&ey);
    scanf("%s",str);
    char ch='E',cv='N';
    int nh=ex-sx,nv=ey-sy;
    if(nh<0){
        nh*=-1;
        ch='W';
    }
    if(nv<0){
        nv*=-1;
        cv='S';
    }
    int posh=0;
    for(posh=0;posh<t&&nh;posh++){
        if(str[posh]==ch){
            nh--;
        }
    }

    int posv=0;
    for(posv=0;posv<t&&nv;posv++){
        if(str[posv]==cv){
            nv--;
        }
    }
    if(nh||nv)printf("-1\n");
    else{
         printf("%d\n",max(posh,posv));
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
