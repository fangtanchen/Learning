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

int a[510],b[510],c[510];
int ab[250010];
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int casei=1;
	int L,N,M,S;
	while(EOF!=scanf("%d%d%d",&L,&N,&M)){
		printf("Case %d:\n",casei++);
		for(int li=0;li<L;li++){
			scanf("%d",&a[li]);
		}
		for(int ni=0;ni<N;ni++){
			scanf("%d",&b[ni]);
		}

		for(int mi=0;mi<M;mi++){
			scanf("%d",&c[mi]);
		}

		scanf("%d",&S);
//		sort(a,a+L);
//		sort(b,b+N);
		sort(c,c+M);
		int ablen=0;
		for(int li=0;li<L;li++){
			for(int ni=0;ni<N;ni++){
				ab[ablen]=a[li]+b[ni];
				ablen++;
			}
		}
		sort(ab,ab+ablen);
#ifdef U_DEBUG
for(int mi=0;mi<M;mi++){
	printf("%d ",c[mi]);
}
printf("\n");
#endif
		while(S--){
			int X;
			scanf("%d",&X);
			bool flag=false;
			for(int mi=0;mi<M;mi++){
				if(flag)break;
				int res=X-c[mi];
				int mid=ablen/2;
				int lf=0;
				int ri=ablen-1;
				while(lf<=ri){
					if(ab[mid]==res){
						flag=true;
						break;
					}else if(ab[mid]<res){
						lf=mid+1;
					}else{
						ri=mid-1;
					}
					mid=(lf+ri)/2;
				}
			
			}
			if(flag)printf("YES\n");
			else printf("NO\n");
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
