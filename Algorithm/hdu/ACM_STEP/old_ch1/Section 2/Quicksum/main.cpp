#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[300];
	while(cin.getline(s,300))
	{
		if(s[0]=='#')break;
		int len=strlen(s);
		int sum=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]!=' ')
				sum+=((i+1)*(s[i]-'A'+1));
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
