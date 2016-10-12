#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double w[3][3];
	char s[4]="WTL";
	while(cin>>w[0][0]>>w[0][1]>>w[0][2])
	{
		for(int i=1;i<3;i++)
		{
			for(int j=0;j<3;j++)
				cin>>w[i][j];
		}
		double ans=1;
		for(int i=0;i<3;i++)
		{
			int maxj=0;
			double max=w[i][0];
			for(int j=1;j<3;j++)
			{
				if(w[i][j]>max)
				{
					max=w[i][j];
					maxj=j;
				}
			}	
			ans*=max;
			cout<<s[maxj]<<" ";
		}
		ans=(ans*0.65-1.0)*2;
		printf("%.2lf\n",ans);
	}
	return 0;
}
