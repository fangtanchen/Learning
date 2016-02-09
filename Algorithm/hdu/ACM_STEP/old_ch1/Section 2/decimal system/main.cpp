#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	char s[20];
	while(cin>>N)
	{
		int sum=0;
		while(N--)
		{
			cin>>s;
			int len=strlen(s);
			int spilt;
			for(spilt=len-1;s[spilt]!='(';spilt--);
			
			int k=0;
			for(int i=spilt+1;s[i]!=')';i++)
			{
				k=k*10+s[i]-'0';
			}
			int part=0;
			for(int i=0;i<spilt;i++)
			{
				part=part*k+s[i]-'0';
			}
			sum+=part;
		}
		cout<<sum<<endl;
	
	}
	return 0;
}
