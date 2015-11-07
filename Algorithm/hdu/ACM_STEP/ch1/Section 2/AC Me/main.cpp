#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int count[200]={0};
	char str[100010];
	while(gets(str))
	{
		memset(count,0,sizeof(count));
		int len=strlen(str);
		for(int i=0;i<len;i++)
		{
			count[str[i]]++;
		}
		for(char c='a';c<='z';c++)
		{
			cout<<c<<":"<<count[c]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
