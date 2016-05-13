#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	__int64 f[51]={0,3,6,6};
	for(int i=4;i<=50;i++)
		f[i]=f[i-1]+2*f[i-2];
	int N;
	while(cin>>N)
		cout<<f[N]<<endl;
	return 0;
}
