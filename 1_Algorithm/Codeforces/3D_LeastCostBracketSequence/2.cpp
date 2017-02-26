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
const int MAXN=1e5+10;
typedef long long int LL;
typedef pair<LL,int> pii;


char s[MAXN];
int now;
set<pii> Q;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>s;
    now=0;
    LL ans=0;
    for(int i=0;s[i];i++){
        if('('==s[i])now++;
        else if(')'==s[i])now--;
        else{
            int a,b;
            cin>>a>>b;
            s[i]=')';
            now--;
            ans+=b;
            Q.insert(make_pair(a-b,i));
        }
        while(now<0){
            if(Q.empty())return 0*printf("-1\n");
            pii p=*Q.begin();
            ans+=p.first;
            s[p.second]='(';
            now+=2;
            Q.erase(Q.begin());
        }
    }
    if(!now)
        printf("%lld\n",ans),puts(s);
    else
        puts("-1");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
