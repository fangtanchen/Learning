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
const int MAXN=1e5+10;

int k,n;
int mp[110][110];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>k;
    int i,j;
    for(i=1;i<=110;i++){
        if(k==0)break;
        int s=0;
        for(j=1;j<i&&(s<=k);j++){
            k-=s;s++;
            mp[i][j]=mp[j][i]=1;
        }
    }
    printf("%d\n",i-1);
    for(int ri=1;ri<i;ri++){
        for(int ci=1;ci<i;ci++){
            printf("%d",mp[ri][ci]);
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
