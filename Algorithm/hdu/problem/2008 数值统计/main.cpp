#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n,n)
	{
		int a,b,c;
		double t;
		a=b=c=0;
		while(n)
		{
			cin>>t;
			if(t<0)a++;
			else if(t==0)b++;
			else c++;
			n--;
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}
