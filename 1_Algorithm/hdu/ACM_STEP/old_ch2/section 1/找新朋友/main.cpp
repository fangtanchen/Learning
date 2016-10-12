#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Eular(int x)
{
	int ans=1;
	
	for(int i=2;i*i<=x;i++)
	{
		if(0==x%i)
		{
			x/=i;
			ans*=(i-1);
			while(0==(x%i))
			{
				x/=i;
				ans*=i;
			}
		}
	}
	if(x>1)
		ans*=(x-1);
		return ans;
}

int main(int argc, char** argv) {
		int t,n;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&n);
			printf("%d\n",Eular(n));
		}
		return 0;
}
