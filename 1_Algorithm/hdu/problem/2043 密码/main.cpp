#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m;
	cin>>m;
	while(m--)
	{
		char s[51];
		cin>>s;
		
		int len=strlen(s);
		if(len<8||len>16)
		{
			printf("NO\n");
			continue;
		}
		
		int a=0,b=0,c=0,d=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]>='A'&&s[i]<='Z')a=1;
			if(s[i]>='a'&&s[i]<='z')b=1;
			if(s[i]>='0'&&s[i]<='9')c=1;
			if(s[i]=='~'||s[i]=='!'||s[i]=='@'
			||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='^')  
			d=1;
		}
		if(a+b+c+d>=3)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
