#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


class CRice{
	public:
		int p;
		int h;
};

int cmp(CRice x, CRice y){
	if(x.p<y.p)return true;
	else return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int C;
	cin>>C;
	while(C--){
		int n,m;
		cin>>n>>m;
		
		CRice rice[1010];
		for(int ri=0;ri<m;ri++){
			cin>>rice[ri].p>>rice[ri].h;
		}
		sort(rice,rice+m,cmp);
		
		double res=0;
		for(int ri=0;ri<m;ri++){
			if(n<=0)break;
			int temp=rice[ri].h*rice[ri].p;
			if(n>=temp){
				res+=rice[ri].h;
				n-=temp;
			}
			else{
				res=res+n*1.0/rice[ri].p;
				n=0;
			}
		}
		printf("%.2lf\n",res);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
