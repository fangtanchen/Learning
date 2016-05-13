#include <iostream>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int f[111];
int main(int argc, char** argv) {
	int n;
	while(cin>>n,n)
	{
		memset(f,0,sizeof(f));
		int x;
		while(n--)
		{
			cin>>x;
			f[x]++;
		}
		cin>>x;
		cout<<f[x]<<endl;
	}
	return 0;
}
