#include <iostream>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int maxt(int x,int y)
{
	return x>y?x:y;
}

int main(int argc, char** argv) {
	int n;
	int Ti_s[110],Ti_e[110];
	int f[10010];
	while(cin>>n,n)
	{
		memset(f,0,sizeof(f));
		for(int i=0;i<n;i++)
			cin>>Ti_s[i]>>Ti_e[i];
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(Ti_e[j]<Ti_e[i])
				{
					int t=Ti_e[j];
					Ti_e[j]=Ti_e[i];
					Ti_e[i]=t;
					t=Ti_s[j];
					Ti_s[j]=Ti_s[i];
					Ti_s[i]=t;					
				}
			}
		}
		int maxx=0;
		int count=0;
		for(int i=0;i<n;i++)		
		{
			if(Ti_s[i]>=maxx){
				count++;
				maxx=Ti_e[i];
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
