#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int f[2][100010];
int num[100010];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int casei=1;casei<=T;casei++){
		
		int N;
		scanf("%d",&N);
		
		int max=-100000;
		int maxst=1;
		int maxed=1;
		
		for(int i=1;i<=N;i++){
			scanf("%d",&num[i]);
			f[0][i]=num[i];
			if(max<num[i]){
				max=num[i];
				maxst=i;
			}
		}
		maxed=maxst;
		int sri=0;
		int dri=1;
		for(int d=2;d<=N;d++){
			int imax=N-d+1;
			for(int i=1;i<=imax;i++){
				f[dri][i]=f[sri][i]+num[i+d-1];
				if(max<f[dri][i]){
					max=f[dri][i];
					maxed=i+d-1;
					maxst=i;
				}else if(max==f[dri][i]){
					if(maxst>i){
						maxst=i;
						maxed=i+d-1;
					}
				}
			}						
			sri=1-sri;
			dri=1-dri;
		}
		if(casei!=1)printf("\n");
		printf("Case %d:\n",casei);		
		printf("%d %d %d\n",max,maxst, maxed);
		
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
