#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[101];
	while(cin>>n,n)
	{
		int t=n;
		while(t--)
		{
			cin>>a[t];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(abs(a[i])<abs(a[j]))
				{
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		cout<<a[0];
		for(int i=1;i<n;i++)
		{
			cout<<" "<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
