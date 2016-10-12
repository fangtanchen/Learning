#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int T;
	int ti = 1;
	cin>>T;
	
	int N;
	int ni=1;
	int a[100001]={0};
	int starti=1,endi=1,sum=0;
	int sumTemp=0,startTemp=1,endTemp=1;
	while(ti<=T)
	{
		cin>>N;
		ni=2;
		cin>>a[1];
		sum = a[1];
		starti=1;
		endi=1;
		sumTemp=a[1];
		startTemp=1;
		endTemp=1;
		
		while(ni<=N)
		{
			cin>>a[ni];
			if(a[ni]<0)
			{
				if(sumTemp<0)
				{
					if(sumTemp<a[ni])
					{
						startTemp = ni;
						endTemp = ni;
						sumTemp = a[ni];
					}
				}	
				else
				{
					if(sumTemp+a[ni]<0)
					{
						if(sumTemp>sum)
						{
							sum = sumTemp;
							starti = startTemp;
							endi = endTemp;
						}
						sumTemp = a[ni];
						startTemp = ni;
						endTemp = ni;
					}
					else
					{
						if(sumTemp>sum)
						{
							sum = sumTemp;
							starti = startTemp;
							endi = endTemp;
						}
						sumTemp+=a[ni];
						endTemp=ni;
					}
				}
			}
			else
			{
				if(sumTemp<0)
				{
					sumTemp = a[ni];
					startTemp = ni;
					endTemp = ni;
				}	
				else
				{
					sumTemp += a[ni];
					endTemp = ni;
				}
			}
			ni++;	
		}
		if(sum<sumTemp)
		{
			sum = sumTemp;
			starti = startTemp;
			endi = endTemp;
		}
		
		cout<<"Case "<<ti<<":"<<endl;
		cout<<sum<<" "<<starti<<" "<<endi<<endl;
		if(ti<T)cout<<endl;
		ti++;
	}
	return 0;
}
