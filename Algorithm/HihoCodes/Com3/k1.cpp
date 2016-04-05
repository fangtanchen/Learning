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

int n;
int db[55][55]
int da[55][55];
int f[55];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
         scanf("%d",f+i);
         da[i][i]=0xffffffff;
         db[i][i]=0;
    }
    for(int d=0;d<n;d++){
        for(int i=1;i<=n;i++){
             da[i][i+d]=da[i][i+d-1]&f[i][i+d];
             db[i][i+d]=db[i][i+d-1]^f[i][i+d];
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
