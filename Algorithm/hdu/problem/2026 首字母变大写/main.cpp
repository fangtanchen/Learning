#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[101];
	while(cin.getline(s,101,'\n'))
	{
		int len=strlen(s);
		int flag=1;
		for(int i=0;i<len;i++)
		{
			if(s[i]==' ')flag=1;
			else
			{
				if(flag)
				{
					if(s[i]>='a'&&s[i]<='z')
						s[i]-=32;
					flag=0;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
