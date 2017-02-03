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
char str[2010];
int top;
int ans;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%s",str)){
            top=0;
            ans=10000;
            for(int i=0;str[i];i++){
                 if(str[i]=='(')top++;
                 else if(str[i]==')')top--;
                 else{
                     ans=min(ans,top);
                 }
            }
            printf("%d\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
