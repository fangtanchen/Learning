#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double a[51][6];
	int n,m;
	double Savg[51],Cavg[6];
	while(cin>>n>>m)
	{
		memset(Savg,0,sizeof(Savg));
		memset(Cavg,0,sizeof(Cavg));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				Savg[i]+=a[i][j];
				Cavg[j]+=a[i][j];
			}
		}
		
		Savg[1]/=m;
		cout.precision(2);
		cout.setf(ios::fixed);
		cout<<Savg[1];
		for(int i=2;i<=n;i++)
		{
			cout<<" ";
			Savg[i]/=m;
			cout<<Savg[i];
		}
		cout<<endl;
		
		Cavg[1]/=n;
		cout<<Cavg[1];
		for(int i=2;i<=m;i++)
		{
			cout<<" ";
			Cavg[i]/=n;
			cout<<Cavg[i];
		}
		cout<<endl;
		
		int count=0;
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]<Cavg[j])
					flag=0;
			}
			if(flag)count++;
		}
		cout<<count<<endl<<endl;
		
	}
	return 0;
}
