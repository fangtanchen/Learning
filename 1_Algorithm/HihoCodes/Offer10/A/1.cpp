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

char str[MAXN];
int T;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>T;
    while(T--){
         cin>>str;
         int cnta=0,cntl=0;
         bool flag=false;
         for(int i=0;str[i];i++){
             if(str[i]=='L'){
                  cntl++;
             }else{
                 cntl=0;
                 if(str[i]=='A')cnta++;
             }
             if(cnta>1||cntl>=3){
                 flag=true;
                 break;
             }
         }
         if(flag)puts("NO");
         else puts("YES");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
