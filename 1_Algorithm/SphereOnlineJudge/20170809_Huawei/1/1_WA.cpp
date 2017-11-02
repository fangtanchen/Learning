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
const int MAXN=500005;

char str[MAXN];
char in[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int slen=0;
    cin>>in;
    int inlen=strlen(in);
    for(int i=2;i<inlen;i+=5){
         str[slen++]=in[i+1];
         str[slen++]=in[i];
    }
    str[slen]=0;
    while(str[slen-1]=='F')str[--slen]=0;
    if(slen==0){
         str[0]='0';
         slen=1;
         str[1]=0;
    }
    cout<<str<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
