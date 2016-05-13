#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int IsLetter(char c)
{
	return  (c>='a'&&c<='z')
		||(c>='A'&&c<='Z');
}
int IsDigit(char c)
{
	return  (c>='0'&&c<='9');
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	getchar();
	char s[51];
	while(n--)
	{
		gets(s);
		int len=strlen(s);
		if(!(IsLetter(s[0]))&&!(s[0]=='_'))
		{
			cout<<"no"<<endl;
			continue;
		}
		int flag=0;
		for(int i=1;i<len;i++)
		{
			if(!(IsLetter(s[i]))&&!(s[i]=='_')&&!(IsDigit(s[i])))
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
	return 0;
}
