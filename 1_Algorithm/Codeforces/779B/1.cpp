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

int K;
int cnt;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>str;
    cin>>K;
    cnt=0;
    int ans=0;
    int N=0;
    int len=strlen(str);
    for(int i=len-1;i>=0;i--){
         if(str[i]=='0')cnt++;
         N=N*10+str[i]-'0';
    }
    if(cnt<K)return 0*printf("%d\n",len-1);

    cnt=0;
    ans=0;
    int i;
    for(i=len-1;i>=0;i--){
         if(cnt>=K)break;
         if(str[i]=='0')cnt++;
         else{
             ans++;
         }
    }
    bool flag=false;
    for(;i>=0;i--){
        if(str[i]!='0') {
            flag=true;
            break;
        }
    }
    if(flag)printf("%d\n",ans);
    else printf("%d",len-1);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
