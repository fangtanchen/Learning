#include <iostream>
#include<cstring>
#include<string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		cin>>s;
		int len=s.length();
		int max=(len/2);
		int flag=1;
		for(int i=0;i<max;i++)
		{
			if(s[i]!=s[len-1-i])
			{
				flag=0;
				break;
			}
		}
		if(flag)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
