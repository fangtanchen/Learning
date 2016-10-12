#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[10];
	int count[10];
	char ts[100];
	while(1)
	{
		memset(count,0,sizeof(count));
		cin.getline(s,10);
		if(s[0]=='#')break;
		cin.getline(ts,100);
		
		int slen=strlen(s);
		int tslen=strlen(ts);
		for(int tsi=0;tsi<tslen;tsi++)
		{
			for(int si=0;si<slen;si++)
			{
				if(s[si]==ts[tsi])
				{
					count[si]++;
					break;
				}
			}
		}
		
		for(int si=0;si<slen;si++)
		{
			cout<<s[si]<<" "<<count[si]<<endl;
		}
	}
	return 0;
}
