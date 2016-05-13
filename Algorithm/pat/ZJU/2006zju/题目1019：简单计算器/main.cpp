#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[222];
	double num[200];
	char op[200];
	while(cin.getline(s,222))
	{
		int len=strlen(s);
		if(len==1&&s[0]=='0')break;
		int numi;
		int opi,i;
		int opflag=0;
		memset(num,0,sizeof(num));
		for(i=0,numi=0,opi=0;i<len;i++)
		{

			if(s[i]>='0'&&s[i]<='9')
			{
				while(s[i]>='0'&&s[i]<='9')
				{
					num[numi]=num[numi]*10+s[i]-'0';
					i++;
				}
				numi++;
				i--;
				
				if(op[opi-1]=='*')
				{
					num[numi-2]=num[numi-2]*num[numi-1];
					numi--;
					num[numi]=0;
					opi--;
				}
				if(op[opi-1]=='/')
				{
					num[numi-2]=num[numi-2]/num[numi-1];
					numi--;
					num[numi]=0;
					opi--;
				}
			}
			else if(s[i]=='*'||s[i]=='/'
				||s[i]=='+'||s[i]=='-')
			{			
				op[opi]=s[i];
				opi++;				
			}					
		}
		double ans=num[0];
		for(int i=1,j=0;i<numi&&j<opi;i++,j++)
		{
			if(op[j]=='+')
			{
				ans+=num[i]	;
			}
			if(op[j]=='-')
			{
				ans-=num[i];
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
