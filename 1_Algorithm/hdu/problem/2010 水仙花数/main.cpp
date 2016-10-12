#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	while(cin>>m>>n)
	{
		int count=0;
		for(int i=m;i<=n;i++)
		{
			int a,b,c;
			a=i/100;
			b=(i%100)/10;
			c=i%10;
			if(i==a*a*a+b*b*b+c*c*c)
			{
				if(count)cout<<" ";
				cout<<i;
				count++;
				
			}
			
		}
		if(!count)cout<<"no";
		cout<<endl;
	}
	return 0;
}
