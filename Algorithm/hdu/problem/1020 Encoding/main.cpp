#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	char c[10000];
	cin>>N;
	while(N)
	{
		cin>>c;
		int len=strlen(c);
		int len_t = len+1;
		int i,j;
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len_t;j++)
			{
				if(c[i]!=c[j])
				{
					int k=j-i;
					if(k>1)printf("%d",k);
					printf("%c",c[i]);
					break;
				}
			}
			i=j-1;
		}
		//printf("%d%c\n",)
		printf("\n");
		N--;
	}
	return 0;
}
