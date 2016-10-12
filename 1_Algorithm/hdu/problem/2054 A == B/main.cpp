#include <iostream>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int findpoint(char* s)
{
	int len=strlen(s);
	for(int i=len-1;i>=0;i--)
	{
		if('.'==s[i])
		return i; 
	}
	return len;
	
}

int main(int argc, char** argv) {
	char a[50000],b[50000];
	
	while(cin>>a>>b)
	{
		int lena=strlen(a);
		int lenb=strlen(b);
		int k=findpoint(a);
		for(int i=lena-1;i>=k;i--)
		{
			if(a[i]=='0'||a[i]=='.')a[i]=0;
			else break;
		}
		k=findpoint(b);
		for(int i=lenb-1;i>=k;i--)
		{
			if(b[i]=='0'||b[i]=='.')a[i]=0;
			else break;
		}
		
		if(!strcmp(a,b))cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	
	return 0;
}
