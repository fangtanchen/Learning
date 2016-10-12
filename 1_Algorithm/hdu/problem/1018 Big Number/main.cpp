#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(n)
	{
		int m;
		double num=0;
		cin>>m;
		for(int i=2;i<=m;i++)
		{
			num+=(1.0*log10(i*1.0));
		}
		cout<<((int)num)+1<<endl;
		n--;
	}
	return 0;
}
