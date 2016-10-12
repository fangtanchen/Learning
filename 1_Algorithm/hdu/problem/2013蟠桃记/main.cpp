#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		int fn=1;
		for(int i=n-1;i>0;i--)
		{
			fn=2*(fn+1);
		}
		printf("%d\n",fn);
	}
	return 0;
}
