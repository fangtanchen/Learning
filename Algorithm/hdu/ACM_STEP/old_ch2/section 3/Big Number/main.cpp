#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		double sum=1;
		for(int i=2;i<=n;i++)
			sum+=(log10((double)i));
		int ans=sum;
		cout<<ans<<endl;
	}
	return 0;
}
