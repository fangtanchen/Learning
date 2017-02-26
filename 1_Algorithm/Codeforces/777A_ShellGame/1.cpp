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
typedef long long int LL;
const int MAXN=1005;

LL N;
int a[3],x;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    N%=6;
    cin>>x;
    a[x]=1;
    for(int i=N+1;i<=6;i++){
        if(1&i)swap(a[0],a[1]);
        else swap(a[1],a[2]);
    }
    int ans=0;
    for(int i=0;i<3;i++){
        if(a[i]!=0){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
