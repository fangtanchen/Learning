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
char ans[MAXN];
int ans_len=0;
int T;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         ans_len=0;
         scanf("%s",str);
         int len=strlen(str);
         while(len>2){
             for(int i=len-1;i>=2;i--){
                 if(str[i]=='0')len--;
                 else break;
             }
             str[len]=0;
             if(len<=2){
                 ans[ans_len]=0;
                 cout<<"0."<<ans<<endl;
                 break;
             }
             else if(str[len-1]!='5'){
                 cout<<"NO"<<endl;
                 break;
             }else{
                 int c=0;
                 for(int i=len-1;i>=2;i--){
                     int tmp=(str[i]+str[i]-'0'-'0')+c;
                     str[i]=tmp%10+'0';
                     c=tmp/10;
                 }
                 ans[ans_len++]=c+'0';
             }
         }
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
