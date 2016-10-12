#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int cmp()

int main(int argc, char** argv) {
	int n;
	int money[1010];
	
	while(cin>>n,n){
		int sum=0;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a;
			cin.get();
			cin>>b;
			money[i]=a*100+b;
			sum+=money[i];
		}
		int pmin=sum/n;
		int pnum=sum%n;
		int pmax=pmin;
		if(pnum)pmax+=1;
		
		int sum1=0;
		int count=0;
		for(int i=0;i<n;i++){
			if(money[i]>pmax){
				sum1+=(money[i]-pmax);
				count++;
			}
		}
		if(count>pnum&&pnum)sum1+=count-pnum;
		printf("$%.2f\n",sum1/100.0);
		
		
	}
	return 0;
}
