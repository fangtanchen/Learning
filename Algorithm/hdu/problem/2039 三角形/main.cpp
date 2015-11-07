#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m;
	cin>>m;
	while(m--)
	{
		double a[3];
		double max=0;
		double sum=0;
		for(int i=0;i<3;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]>max)max=a[i];
		}
		sum-=max;
		if(sum>max)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
