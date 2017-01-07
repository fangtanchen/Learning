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
const int MAXN=2005;
char str[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    scanf("%s",str+1);

    bool flag1=false,flag2=false;
    for(int i=1;i<=N;i++){
         if(str[i]=='R'){
             flag1=true;
             break;
         };
    }

    for(int i=N;i>=1;i--){
         if(str[i]=='L'){
             flag2=true;
             break;
         };
    }

    int s=1,t=1;
    if(flag1&&flag2){
        int i;
        for(i=1;i<=N;i++){
            if(str[i]=='R'){
                s=i;break;
            }
        }
        for(;i<=N;i++){
            if(str[i]!='R'){
                t=i-1;break;
            }
        }
    }else if(flag1){
        int i;
        for(i=1;i<=N;i++){
            if(str[i]=='R'){
                s=i;break;
            }
        }
        for(;i<=N;i++){
            if(str[i]!='R'){
                t=i;break;
            }
        }
    }else if(flag2){
       int i;
       for(i=N;i>=1;i--){
           if(str[i]=='L'){
               s=i;break;
           }
       }
       for(;i>=1;i--){
           if(str[i]!='L'){
               t=i;break;
           }
       }
    }
    printf("%d %d\n",s,t);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
