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
const int MAXN=1e6+10;

char kmp_pat[MAXN],kmp_str[MAXN];
int kmp_nxt[MAXN];
int N;

void KMP_Next(char* in,int inlen,int *nxt){
    memset(nxt,0,sizeof(nxt));
    nxt[0]=-1;
    for(int i=1;i<=inlen;i++){
        int j=nxt[i-1];
        while(j!=-1){
            if(in[j]==in[i-1]){
                nxt[i]=j+1;
                break;
            }
            j=nxt[j];
        };
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    while(N--){
         cin>>kmp_pat;
         cin>>kmp_str;
         int patlen=strlen(kmp_pat);
         KMP_Next(kmp_pat,strlen(kmp_pat),kmp_nxt);
         int ans=0;
         int pi=0;
         for(int si=0;kmp_str[si];){
             if(kmp_pat[pi]==kmp_str[si]){
                 si++;
                 pi++;
             }else{
                 pi=kmp_nxt[pi];
             }
             if(pi==-1){
                  pi++;si++;
             }
             if(pi==patlen){
                 ans++;
                 pi=kmp_nxt[pi];
             }
         }
         cout<<ans<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
