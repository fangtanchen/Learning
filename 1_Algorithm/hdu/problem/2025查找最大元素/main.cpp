#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[101];
	while(cin>>s)
	{
		char c=s[0];
		int len=strlen(s);
		 for(int i=1;i<len;i++)
		 {
		 	if(s[i]>c)c=s[i];
		 }
		 for(int i=0;i<len;i++)
		 {
		 	cout<<s[i];
		 	if(s[i]==c)
		 	{
		 		cout<<"(max)";
		 	}
		 }
		 cout<<endl;
	}
	return 0;
}
