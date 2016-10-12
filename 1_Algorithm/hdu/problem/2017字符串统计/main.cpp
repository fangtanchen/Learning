#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	
	while(n)
	{
		char c[200];
		cin>>c;
		int len=strlen(c);
		int count=0;
		for(int i=0;i<len;i++)
		{
			if(c[i]>='0'&&c[i]<='9')
			{
				count++;
			}
		}	
		printf("%d\n",count);
		n--;
	}
	return 0;
}
