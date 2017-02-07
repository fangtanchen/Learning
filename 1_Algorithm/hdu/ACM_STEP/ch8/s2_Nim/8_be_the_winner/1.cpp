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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int T,a;
    while(EOF!=scanf("%d",&T)){
        int flag=0,ans=0;
        for(int i=0;i<T;i++){
            scanf("%d",&a);
            ans^=a;
            if(a!=1)flag=1;
        }
        if(flag){
             if(ans)printf("Yes\n");
             else puts("No");
        }else{
            if(T&1)puts("No");
            else puts("Yes");
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
