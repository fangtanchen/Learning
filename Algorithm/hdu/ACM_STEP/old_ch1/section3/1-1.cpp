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
		if(N<0||M<0){
			cout<<0<<endl;
			continue;
		}
		double ans=0;
		for(int i=0;i<N;i++){
			cin>>pp[i].j>>pp[i].f;
			if(pp[i].f)pp[i].jpf=pp[i].j*1.0/pp[i].f;
			else pp[i].jpf=MAX_INT;
		}
		sort(pp,pp+N,cmp);
		//for(int i=0;i<N;i++){
		//	cout<<pp[i].jpf<<endl;
		//}
		for(int i=0;i<N;i++){
			if(M>pp[i].f){
				M-=pp[i].f;
				ans+=pp[i].j;
			}
			else{
				ans+=(M*pp[i].jpf);
				break;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}

