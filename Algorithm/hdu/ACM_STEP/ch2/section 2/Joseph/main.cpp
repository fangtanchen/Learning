#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int res[14]={0};

int fun(int x)
{
	if(res[x])
		return res[x];
	else
	{
		int ans=x;
		for(ans=x+1;;ans++)
		{
			int total=2*x;
			int flag=0;
			for(int i=ans;;i+=(ans-1))
			{
				if(total==x)
				{
					flag=1;
					break;
				}
				if(i>total){					
					i=(i%total)?i%total:total;
				}
				if(i<=x)
				{
					break;
				}
				else
				{
					total--;
					continue;
				}
			}
			if(flag)
			{
				res[x]=ans;	
				break;		
			}
		}
		
		return res[x];
	}
}

int main(int argc, char** argv) {
	int k;
	while(cin>>k,k)
	{
		cout<<fun(k)<<endl;
	}
	return 0;
}
