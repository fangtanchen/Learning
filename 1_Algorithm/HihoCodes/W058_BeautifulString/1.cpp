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
const int MAXN=1e7+10;

char str[MAXN];
char ch[3];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
         int N;
         scanf("%d",&N);
         scanf("%s",str);
         int cnt[3]={0};
         int si=0;
         for(si=0;si<N;si++){
             cnt[0]++;
             if(str[si]!=str[si+1]){
                 ch[0]=str[si];
                 break;
             }
         }
         for(si++;si<N;si++){
             cnt[1]++;
             if(str[si]!=str[si+1]){
                 ch[1]=str[si];
                 break;
             }
         }
         bool flag=false;
         for(si++;si<N;si++){
              cnt[2]++;
              if(str[si]!=str[si+1]){
                  ch[2]=str[si];
                  if(cnt[1]<=cnt[2]
                          &&(cnt[1]<=cnt[0])
                          &&(1==ch[2]-ch[1])
                          &&(1==ch[1]-ch[0])){
                      flag=true;
                      break;
                  }else{
                      cnt[0]=cnt[1];cnt[1]=cnt[2];
                      cnt[2]=0;
                      ch[0]=ch[1];ch[1]=ch[2];
                  }
              }
         }
         if(flag)puts("YES");
         else puts("NO");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
