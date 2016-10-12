#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[6]={100,50,10,5,2,1};
	while(cin>>n,n)
	{
		int count=0;
		for(int i=1;i<=n;i++)
		{
			
			int sal;
			cin>>sal;
			int pt=0;
			while(sal)
			{
				count+=sal/a[pt];
				sal%=a[pt];
				pt++;
			}
		}
		cout<<count<<endl;
	}
	
	return 0;
}
