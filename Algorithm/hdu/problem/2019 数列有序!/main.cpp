#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	int a[101];
	while(cin>>n>>m,n||m)
	{
		int loc=0;
		a[0]=m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(m>=a[i])
			{
				loc++;
			}
		}
		
		for(int i=1;i<=loc;i++)
			cout<<a[i]<<" ";
		cout<<m;
		for(int i=loc+1;i<=n;i++)
		{
			cout<<" "<<a[i];
		}
		cout<<endl;
		
	}
	return 0;
}
