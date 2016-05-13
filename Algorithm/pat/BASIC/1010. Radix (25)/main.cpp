#include <iostream>
#include<cstdio>
#include<cstring>
#include<stdint.h>
using namespace std;
#define __int64 long long

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
__int64 fun(char* s,int radix)
{
	int len=strlen(s);
	__int64 ans=0;
	for(int i=0;i<len;i++)
	{
		int temp=0;
		if(s[i]>='0'&&s[i]<='9')temp=s[i]-'0';
		else temp=s[i]-'a'+10;
		ans=ans*radix+temp;		
	}
	return ans;
}
int main(int argc, char** argv) {
	char s[11]="zzzzzzzzzz";
	__int64 k=fun(s,36);
	cout<<k<<endl;
	
	char n[3][11];
	int radix;
	int tag;
	while(cin>>n[1]>>n[2]>>tag>>radix)
	{
		int len[3]={0};
		int pop=3-tag;
		len[tag]=strlen(n[tag]);
		len[pop]=strlen(n[pop]);
		
		char minRc=0;
		int minR=0;
		for(int i=0;i<len[pop];i++)
			if(n[pop][i]>minRc)minRc=n[pop][i];
		if(minRc>='0'&&minRc<='9')minR=minRc-'0';
		else if(minRc>='a'&&minRc<='z')minR=minRc-'a'+10;
		
		__int64 n1=fun(n[tag],radix);
		int ans=-1;
		for(int i=minR+1;i<=36;i++)
		{
			__int64 n2=fun(n[pop],i);
			if(n2==n1){
				ans=i;
				break;
			}
			else if(n2>n1)break;			
		}
		if(ans==-1)cout<<"Impossible"<<endl;
		else cout<<ans<<endl;
		
		//cout<<n1<<"  "<<n2<<"  "<<tag<<"  "<<radix<<endl;
	}
	return 0;
}
