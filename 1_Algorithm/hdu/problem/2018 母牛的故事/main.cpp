#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//��i�������ţ�� i-3��ţ����Ŀ������ f[i]=f[i-1]+f[i-3]�ǵ�i��ţ������ 
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
