#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gcd(int x,int y)
{
	int t;
	while(t=x%y)
	{		
		x=y;
		y=t;	
	}
	return y;
}

int main(int argc, char** argv) {
	char s[20];
	int ni;
	cin>>ni;
	while(ni--)
	{			
		while(cin>>s)
		{
			int p1=1,num1=0;
			int len=strlen(s);
			int i=0;
			for(i=2;i<len&&s[i]!='(';i++)
			{
				p1*=10;
				num1=10*num1+s[i]-'0';
			}
			int p2=1,num2=0;
			if(s[i]=='(')
			{
				p2=num2=0;
				int j;
				for(j=i+1;j<len&&s[j]!=')';j++)
				{
					num2=10*num2+s[j]-'0';
					p2*=10;
				}
				int t=j-i-1;
				for(int k=0;k<t;k++)			
				{
					p2=p2*10+9;
				}
			}
			int h=p2*num1+num2;
			int g=p1*p2;
			int t=gcd(h,g);
			cout<<h/t<<"/"<<g/t<<endl;			
		}
	}
	return 0;
}
