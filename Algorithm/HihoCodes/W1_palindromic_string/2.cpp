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


const int MAXN=1<<23;
char s[MAXN];
char str[MAXN];
int rad[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    str[0]='$';
    str[1]='#';
    int n;
    scanf("%d",&n);
    while(n--){
         scanf("%s",s);
         int ki=2;
         for(int i=0;s[i];i++){
             str[ki++]=s[i];
             str[ki++]='#';
         }
         int ma=0,re=1;
         for(int i=1;i<ki;i++){
             if(i<ma)rad[i]=min(ma-i,rad[2*re-i]);
             else rad[i]=1;
             while(str[i-rad[i]]==str[i+rad[i]])rad[i]++;
             if(i+rad[i]>ma){
                  re=i;
                  ma=i+rad[i];
             }
         }
         int ans=0;
         for(int i=1;i<ki;i++){
             ans=max(rad[i]-1,ans);
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
