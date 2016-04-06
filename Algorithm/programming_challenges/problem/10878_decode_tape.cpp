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

char map[15];
char ans[1000];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.getline(map,15,'\n');
    int len=0;
    while(cin.getline(map,15,'\n'),!cin.eof()){
         int q=64;
         ans[len]=0;
         for(int i=2;i<=9;i++){
             if(map[i]=='.')continue;
             if(map[i]=='o')ans[len]=ans[len]+q;
             q/=2;
         }
         len++;
    }
    printf("%s\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
