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

class CBlock{
	public:
		int len;
		int wid;
		int hei;
};

int cmp_int(int x, int y){
	if(x>=y)return true;
	else return false;
}

int cmp(CBlock x, CBlock y){
	if(x.len>y.len){
		return true;
	}else if(x.len==y.len){
		if(x.wid>y.wid){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	CBlock blocks[400];
	int casei=1;
	while(EOF!=scanf("%d",&n),n){
		int a[3];
		for(int i=0;i<n;i++){	
			scanf("%d%d%d", &a[0], &a[1], &a[2]);
			
			int temp=6*i;
			for(int ti=0;ti<3;ti++){				
				for(int pi=0;pi<3;pi++){
					if(pi==ti)continue;
					blocks[temp].len=a[ti];
					blocks[temp].wid=a[pi];
					blocks[temp].hei=a[3-pi-ti];
					temp++;	
				}
			}					
		}
		int num_blocks=6*n;
		sort(blocks,blocks+num_blocks,cmp);
			
		#ifdef U_DEBUG
		cout<<"test sort:"<<endl;
		for(int i=0;i<num_blocks;i++){
			cout<<blocks[i].len<<" "<<blocks[i].wid<<" "<<blocks[i].hei<<endl;
		}
		cout<<endl<<endl<<endl;
		#endif
		
		int dp[400];
		dp[0]=blocks[0].hei;
		for(int i=1;i<num_blocks;i++){
			dp[i]=blocks[i].hei;
			for(int j=i-1;j>=0;j--){
				if((blocks[j].len>blocks[i].len)
				&&(blocks[j].wid>blocks[i].wid)){
					int temp=dp[j]+blocks[i].hei;
					if(dp[i]<temp){
						dp[i]=temp;
					}
				}
			}
		}
		
		int max_hei=dp[0];
		for(int i=num_blocks-1;i>0;i--){
			if(dp[i]>max_hei){
				max_hei=dp[i];
			}
		}
		printf("Case %d: maximum height = %d\n",casei,max_hei);
		casei++;
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
