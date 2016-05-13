#include <iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmp(float a, const float b){
	if(a>b)return true;
	else return false;
}

int main(int argc, char** argv) {
	int n;
	float money[1010];
	while(cin>>n,n){
		float sum=0;
		for(int i=0;i<n;i++){
			cin>>money[i];
			sum+=money[i];
		}
		float p_ave=sum/n;
		sort(money,money+n,cmp);
		int p=sum*100;
		int pnum=p%n;
		float p_min=p/n*1.0/100;
		float p_max=p_min;
		if(pnum)p_max=(p/n+1)*1.0/100;
		
		float ans=0;
		int ti=0;
		for(ti=0;ti<pnum;ti++) {
			if(money[ti]>p_max){
				ans+=(money[ti]-p_max);
			}
			else break;
		}
		for(ti=pnum;money[ti]>p_min;ti++){
			ans+=(money[ti]-p_min);
		}
		 
		
		printf("$%.2f\n",ans) ;
				
	/*	for(int i=0;i<n;i++){
			cout<<money[i]<<endl;
		}*/
		
		
	}
	return 0;
}
