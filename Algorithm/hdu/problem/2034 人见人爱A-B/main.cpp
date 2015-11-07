#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n;
	int a[100][2],b;
	while(cin>>n>>m,n||m)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0];
			a[i][1]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i][0]>a[j][0])
				{
					int temp=a[i][0];
					a[i][0]=a[j][0];
					a[j][0]=temp;
				}
			}
		}
		int count=n;
		for(int i=0;i<m;i++)
		{
			cin>>b;
			for(int j=0;j<n&&a[j][0]<=b;j++)
			{
				if(a[j][0]==b)
				{
					a[j][1]=0;
					count--;
				}
			}
		}
		if(!count)cout<<"NULL"<<endl;
		else
		{
			
			for(int i=0;i<n;i++)
			{
				if(a[i][1])cout<<a[i][0]<<" ";
			}
			cout<<endl;
		}
		
	/*	for(int i=0;i<m;i++)
		{
			for(int j=i+1;i<m;j++)
			{
				if(b[i]>b[j])
				{
					int temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
		
		for(int i=0;i<m;)*/
		
	}
	return 0;
}
