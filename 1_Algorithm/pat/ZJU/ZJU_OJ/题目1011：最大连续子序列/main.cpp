#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int num[10001];
	int k;
	int sum[10001];
	while(cin>>k,k)
	{			
		int max=0;
		int maxi=0;
		int maxj=0;
		for(int i=1;i<=k;i++)
			cin>>num[i];
		
		int i=1;
		for(i=1;i<=k;i++)
		{
			if(num[i]<0)continue;
			else break;			
		}
		//全是负数		
		if(i==k+1)
		{
			cout<<0<<" "<<num[1]<<" "<<num[k]<<endl;
		}
		else
		{
			sum[i-1]=0;
			for(int j=i;j<=k;j++)
			{
				sum[j]=sum[j-1]+num[j];
				if(sum[j]>max)
				{
					max=sum[j];
					maxj=j;
					maxi=i;
				}
			}
			
			for(i=i+1;i<=k;i++)
			{
				for(int j=i;j<=k;j++)
				{
					sum[j]=sum[j]-num[i-1];
					if(sum[j]>max)
					{
						max=sum[j];
						maxj=j;
						maxi=i;
					}
				}
			}
			
			cout<<max<<" "<<num[maxi]<<" "<<num[maxj]<<endl;
		}
		
		
	}
	return 0;
}
