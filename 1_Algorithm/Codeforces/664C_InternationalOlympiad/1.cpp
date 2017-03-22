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

int from[10]={0,1980,1900,2000,0,0};
int base[11]={1,10,100,1000,10000,100000};
int bord[]={0,8,98,98,3098,13098,113098,1113098,11113098,111113098};


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    cin>>n;
    char str[20];
    for(int i=1;i<10;i++){
         base[i]=base[i-1]*10;
    }
    while(n--){
        cin>>str ;
        int slen=strlen(str);
        int num=slen-4;
        int pp=0;
        for(int i=4;i<slen;i++){
             pp=pp*10+str[i]-'0';
        }
        if(pp<=bord[num])pp+=base[num];
        pp+=from[num];
        printf("%d\n",pp);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
