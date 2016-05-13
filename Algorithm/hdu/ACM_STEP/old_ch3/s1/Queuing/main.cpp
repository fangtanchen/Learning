#include <iostream>
using namespace std;
#include<cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char f[1000004]={1,2,4,6};
int main(int argc, char** argv) {
	int L,M;
	while(cin>>L>>M)
	{			
		for(int i=4;i<=L;i++)		
			f[i]=(f[i-4]+f[i-3]+f[i-1])%M;		
		printf("%d\n",f[L]);
	}
	return 0;
}
