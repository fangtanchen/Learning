#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int f[21]={0,1};
	for(int i=2;i<21;i++)
	{
		f[i]=f[i-1]*2-f[i-2];
	}
	
	int T,i;
	cin>>T;
	i=0;
	while(i++<T)
	{
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
	
	return 0;
}
