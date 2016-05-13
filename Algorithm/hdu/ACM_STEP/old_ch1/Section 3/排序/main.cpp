#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char str[1010];
	int num[1010];
	while(cin>>str)
	{
		memset(num,0,sizeof(num));
		int numi=0;
		int len;
		
		int htil=0;
		while(str[htil]=='5')htil++;
		
		len=strlen(str);
		
		for(int i=htil;i<len;i++)
		{					
			if(str[i]=='5')
			{
				while(str[i+1]=='5')
					i++;
				numi++;
			}
			else 
			{
				num[numi]*=10;
				num[numi]+=(str[i]-'0');
			}
		}
		if(str[len-1]=='5')numi--;
		for(int i=0;i<=numi;i++)
		{
			for(int j=i+1;j<=numi;j++)
			{
				if(num[i]>num[j])
				{
					int t=num[i];
					num[i]=num[j];
					num[j]=t;
				}
			}
		}
		
		for(int i=0;i<numi;i++)
			cout<<num[i]<<" ";
		cout<<num[numi]<<endl;
	
	}
	return 0;
}
