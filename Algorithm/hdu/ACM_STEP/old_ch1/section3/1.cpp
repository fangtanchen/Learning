#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


#define MAX_INT 5000
class WareHouse{
public:
	int j;
	int f;
	double jpf;
};

int cmp(WareHouse x, WareHouse y){
	if(x.jpf>y.jpf)return 1;
	else return 0;
}

int main(){
	int M,N;
	WareHouse pp[1010];
	while(cin>>M>>N,M!=-1||N!=-1){
		int count=0;
		double ans=0;
		for(int i=0;i<N;i++){
			cin>>pp[count].j>>pp[count].f;
			if(pp[count].f==0)ans+=pp[count].j;
			else{
				pp[count].jpf=pp[count].j*1.0/pp[count].f;
				count++;
			}
		}
		sort(pp,pp+count,cmp);
		for(int i=0;i<count;i++)
		{
			if(pp[i].f<M){
				M-=pp[i].f;
				ans+=pp[i].j;
			}
			else{
				ans=ans+pp[i].jpf*M;
				break;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}

