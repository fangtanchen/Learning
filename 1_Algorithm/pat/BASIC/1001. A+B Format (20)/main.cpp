#include <iostream>
#include<cstdio>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	while(cin>>a>>b)
	{
		int sum=a+b;
		int t[5]={0};
		int ti=0;
		int flag=0;
		if(sum<0)
		{
			flag=1;
			sum*=-1;
		}
		
		if(!sum)
		{
			cout<<"0"<<endl;
			continue;
		}
		
		for(ti=0;sum;ti++,sum/=1000)
		{
			t[ti]=sum%1000;
		}
		if(flag)cout<<"-";
		cout<<t[ti-1];
		ti--;
		while(ti--)
		{			
			printf(",%03d",t[ti]);
		}
		cout<<endl;
		
	}
	return 0;
}
