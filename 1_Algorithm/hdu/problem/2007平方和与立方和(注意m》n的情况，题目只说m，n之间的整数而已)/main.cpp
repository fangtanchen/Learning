#include <iostream>

#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n;
	while(cin>>m>>n)
	{
		if(m>n)
		{
			int temp=m;
			m=n;
			n=temp;
		}
		int x=0,y=0;
		for(int i=m;i<=n;i++)
		{
			if(i%2)
			{
				y+=(i*i*i);
			}
			else
			{
				x+=(i*i);
			}
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
