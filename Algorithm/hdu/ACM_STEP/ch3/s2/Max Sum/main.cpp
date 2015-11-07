#include <iostream>
using namespace std;
#include<cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {	
	int T;
	cin>>T;
	for(int Ti=1;Ti<=T;Ti++)
	{				
		int N,temp;
		cin>>N>>temp;
		int beg=1,end=1,pos=1;
		int max=temp;
		int sum=temp;
		for(int i=2;i<=N;i++)
		{
			cin>>temp;
			if(sum+temp<temp)
			{
				sum=temp;
				pos=i;				
			}
			else
				sum+=temp;
			if(sum>max)
			{
				beg=pos;
				end=i;
				max=sum;
			}			
		}
		printf("Case %d:\n",Ti);
		cout<<max<<" "<<beg<<" "<<end<<endl;
		if(T!=Ti)cout<<endl;
	}
	return 0;
}
