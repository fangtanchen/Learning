#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=65;
const int MAXM=10010;

char str[MAXN],query[MAXN];
int N;
string dp[MAXM];
int dplen;
set<string>  st;


void Init(){
    dplen=0;
    st.clear();
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    scanf("%s",str);
    scanf("%d",&N);
    int slen=strlen(str);
    for(int i=0;i<slen;i++){
        char tmp[MAXN];
        int tlen=0;
        memset(tmp,0,sizeof(tmp));
        for(int j=i;j<slen;j++){
            tmp[tlen++]=str[j];
            if(!st.count(tmp)){
                st.insert(tmp);
                dp[dplen++]=tmp;
            }
        }
    }
    sort(dp,dp+dplen);
    for(int i=0;i<slen;i++){
        char tmp[MAXN];
        int tlen=0;
        memset(tmp,0,sizeof(tmp));
        for(int j=0;j<slen;j++){
            tmp[tlen++]=str[j];

        }
    }


    for(int ni=0;ni<N;ni++){
        scanf("%s",query) ;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
