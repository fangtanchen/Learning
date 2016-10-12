#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//第i年出生的牛是 i-3年牛的数目，所以 f[i]=f[i-1]+f[i-3]是第i年牛的数量 
int main(int argc, char** argv) {
	int n;
	int f[55]={0,1,2,3,4};
	for(int i=5;i<55;i++)
	{
		f[i]=f[i-1]+f[i-3];
	}
	while(cin>>n,n)
	{
		printf("%d\n",f[n]);
	}
	return 0;
}
