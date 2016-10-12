#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[100];
	while(cin>>n,n)
	{
		int mini=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<a[mini])mini=i;
		}
		int temp=a[mini];
		a[mini]=a[0];
		a[0]=temp;
		
		for(int i=0;i<n-1;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[n-1]<<endl;
		
	}
	return 0;
}
