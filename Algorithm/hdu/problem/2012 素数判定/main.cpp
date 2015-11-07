#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,y;
	while(cin>>x>>y,x||y)
	{
		int flag=0;
		for(int i=x;i<=y;i++)
		{
			int num=i*i+i+41;
			int loopn=num/2;
			for(int j=2;j<loopn;j++)
			{
				if(num%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag)break;
		}
		if(flag)printf("Sorry\n");
		else printf("OK\n");
		
	}
	return 0;
}
