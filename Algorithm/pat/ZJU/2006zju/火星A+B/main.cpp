#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int IsPrime(int n)
{
	int max=sqrt(n*1.0);
	for(int i=2;i<=max;i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}

int main(int argc, char** argv) {
	
	int prime[30];
	int count=0;
	for(int i=2;count<30;i++)
	{
		if(IsPrime(i))
		{			
			prime[count]=i;
			count++;			
		}
	}
	char a[200],b[200];
	int ca[50],cb[50];
	while(cin>>a>>b)
	{
		memset(ca,0,sizeof(ca));
		memset(cb,0,sizeof(cb));
		int alen=strlen(a);
		int blen=strlen(b);
		int cai=0,cbi=0;
		int aflag=0,bflag=0;
		for(int ai=0;ai<alen;ai++)
		{
			if(a[ai]==',')cai++;
			else
			{
				ca[cai]=10*ca[cai]+a[ai]-'0';
				if(ca[cai])aflag=1;
			}
		}
		for(int bi=0;bi<blen;bi++)
		{
			if(b[bi]==',')cbi++;
			else
			{
				cb[cbi]=10*cb[cbi]+b[bi]-'0';
				if(cb[cbi])bflag=1;
			}
		}
		if(!aflag&&!bflag)break;
		int cc[50];
		int cci=cai>cbi?cai:cbi;
		int ki=0,carry=0;
		int ai,bi,ci;
		for(ai=cai,bi=cbi,ci=cci;ai>=0&&bi>=0;ai--,bi--,ci--,ki++)
		{
			int temp=ca[ai]+cb[bi]+carry;
			cc[ci]=temp%prime[ki];
			carry=temp/prime[ki];
		}
		if(ai<0)
		{
			for(;bi>=0;bi--,ki++,ci--)	
			{
				int temp=cb[bi]+carry;
				cc[ci]=temp%prime[ki];				
				carry=temp/prime[ki];
			}
		}
		else
		{
			for(;ai>=0;ai--,ci--,ki++)
			{
				int temp=ca[ai]+carry;
				cc[ci]=temp%prime[ki];				
				carry=temp/prime[ki];
			}
		}
		
		if(carry)cout<<carry<<",";
		for(int i=0;i<cci;i++)
		{
			cout<<cc[i]<<",";
		}
		cout<<cc[cci]<<endl;
		
		
	}
	return 0;
}
