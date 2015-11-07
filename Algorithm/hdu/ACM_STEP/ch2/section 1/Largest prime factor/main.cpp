#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int a[1000000];
int main(int argc, char** argv) {

	memset(a,0,sizeof(a));
	
	int pos=1;
	for(int i=2;i<1000000;i++)
	{
		if(!a[i])
		{
			a[i]=pos;
			for(int j=i+i;j<1000000;j+=i)
			{
				a[j]=pos;
			}
			pos++;
		}
	}
	int n;
	while(~scanf("%d",&n))
	{
		printf("%d\n",a[n]);
	}
	return 0;
}
