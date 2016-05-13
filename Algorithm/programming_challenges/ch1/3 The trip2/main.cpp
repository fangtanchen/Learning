#include <iostream>
#include<cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int n;
	double payment[1010];
	char temp[1010];
	while(cin>>n&&n){
		double sum=0.0;
		for(int i=0;i<n;i++){
			cin>>payment[i];
			sum+=payment[i];
		}
		double aver=((int)(sum*100))/n/100.0;
		
	//	cout<<aver<<endl;
		sprintf(temp,"%.2lf",aver);
		sscanf(temp,"%lf",&aver);
	//	cout<<aver<<endl;
		
		double ans=0.0;
		int count=0;
		for(int i=0;i<n;i++){
			if(payment[i]>aver+0.01){
				ans+=(payment[i]-aver-0.01);
				count++;
			}
		}
		if(count*0.01>sum-aver*n)
			ans+=(count*0.01-sum+aver*n);
			
		printf("$%.2lf\n",ans);
		
	}
	return 0;
}
