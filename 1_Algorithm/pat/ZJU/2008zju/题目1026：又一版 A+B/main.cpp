#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	unsigned int a,b;
	int m;
	while(cin>>m,m)
	{
		cin>>a>>b;
		unsigned int ans=a+b;
		if(!ans)
		{
			cout<<0<<endl;
			continue;
		}
		int f[40];
		int fi=0;
		while(ans)
		{
			f[fi]=(ans%m);
			ans/=m;
			fi++;
		}
		
		for(int i=fi-1;i>=0;i--)
			cout<<f[i];
		cout<<endl;
		
	}
	return 0;
}
