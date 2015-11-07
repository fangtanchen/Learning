#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int n;
	while(EOF!=scanf("%d",&n))
	{
		int s[11];
		int len=0;
		
		while(n)
		{
			s[len++]=n%2;
			n/=2;	
		}
		for(int i=len-1;i>=0;i--)
			cout<<s[i];
		cout<<endl;
	}
	
	return 0;
}
