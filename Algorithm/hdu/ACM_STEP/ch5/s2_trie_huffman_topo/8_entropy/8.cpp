#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<string>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int cmp(const void *a,const void * b){
    return *(int *)b-*(int *)a;
}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    string str;
    int num[30];
    while(cin>>str,str!="END"){
        memset(num,0,sizeof(num));
        int i;
        for(i=0;str[i];i++){
            if(str[i]=='_')num[26]++;
            else num[str[i]-'A']++;
        }
        int tlen=i;
        qsort(num,28,sizeof(int),cmp);
        int len=0;
        for(len=0;len<27&&num[len];len++)
            ;
        int ans=0;
        for(int i=len-1;i>0;i--){
            num[i-1]+=num[i];
            ans+=num[i-1];
            qsort(num,i,sizeof(int),cmp);
        }
        if(len==1)ans=num[0];
        printf("%d %d %.1lf\n",8*tlen, ans,tlen*8.0/ans);
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
