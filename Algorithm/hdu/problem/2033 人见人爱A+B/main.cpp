#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(n--)
	{
		int a[3],b[3];
		for(int i=0;i<3;i++)
			cin>>a[i];
		for(int i=0;i<3;i++)
		{
			cin>>b[i];
			a[i]+=b[i];
		}	
		a[1]+=a[2]/60;
		a[2]%=60;
		a[0]+=a[1]/60;
		a[1]%=60;
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	}
	return 0;
}
