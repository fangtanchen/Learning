#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		int res=1;
		int x;
		while(n)
		{
			cin>>x;
			if(x%2)res*=x;
			n--;
		}
		cout<<res<<endl;
	}
	return 0;
}
