#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		
		char s[500];
		//cin.getline(s,500);
		gets(s);
		int count=0;
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]&0x80)count++;
		}
		cout<<count/2<<endl;
	}
	return 0;
}
