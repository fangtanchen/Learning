#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(n--)
	{
		double sum=0;
		int m;
		cin>>m;
		for(int i=2;i<=m;i++)
		{
			sum+=log10((double)i);
		}
		int ans=sum+1;
		cout<<ans<<endl;
	}
	return 0;
}
