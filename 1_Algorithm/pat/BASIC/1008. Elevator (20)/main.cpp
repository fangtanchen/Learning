#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		int ans=5*n;
		int old=0;
		int newi;
		while(n--)
		{
			cin>>newi;
			int temp=newi-old;
			if(temp>0)ans+=(6*temp);
			else ans-=(4*temp);
			old=newi;
		}
		cout<<ans<<endl;
	}
	return 0;
}
