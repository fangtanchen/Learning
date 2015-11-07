#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n;
int sum[101]={0};
int si=0;
void f(int place,  int cnt)
{
	if(place==n-1)
	{				
		sum[0]+=cnt+1;
		int i=0;
		int c=0;
		while(sum[i]>10000)
		{			
			c=sum[i]/10000;
			sum[i]%=10000;
			i++;
			sum[i]+=c;
		}
	}
	else 
	{
		  int p=cnt+1;
		  int t=place+1;
		for(int i=1;i<=p;i++)
		{
			f(t,i);
		}
	}
	
}

int main(int argc, char** argv) {
	
	while(EOF!=scanf("%d",&n))
	{
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		memset(sum,0,sizeof(sum));
		f(1,1);
		int i;
		for(i=100;sum[i]==0;i--);
		printf("%d",sum[i--]);
		for(;i>=0;i--)
			printf("%04d",sum[i]);
		printf("\n");
	}
	
	
	return 0;
}
