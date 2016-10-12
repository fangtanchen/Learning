#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[30][30]={0};
	for(int i=0;i<30;i++)
	{
		a[i][0]=a[i][i]=1;
	}
	for(int i=2;i<30;i++)
	{
		for(int j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<a[i][0];
			for(int j=1;j<=i;j++)
			{
				cout<<" "<<a[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
