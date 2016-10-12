#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	getchar();
	char s[101];
	char c[5]={'a','e','i','o','u'};
	while(n--)
	{
		gets(s);
		int num[5]={0};
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			switch(s[i])
			{
				case 'a':
					num[0]++;
					break;				
				case 'e':
					num[1]++;
					break;				
				case 'i':
					num[2]++;
					break;				
				case 'o':
					num[3]++;
					break;				
				case 'u':
					num[4]++;
					break;
			}
		}
		for(int i=0;i<5;i++)
			cout<<c[i]<<":"<<num[i]<<endl;
		if(n)cout<<endl;
	}
	return 0;
}
