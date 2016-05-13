#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i=1000;
	while(i<10000)
	{
		int sumd=0;
		int t=i;
		while(t)
		{
			sumd+=(t%10);
			t/=10;
		}
		int sum12=0;
		t=i;
		while(t)
		{
			sum12+=(t%12);
			t/=12;
		}
		int sum16=0;
		t=i;
		while(t)
		{
			sum16+=(t%16);
			t/=16;
		}
		
		if(sumd==sum12 && sumd==sum16)cout<<i<<endl;
		
		i++;
	}
	return 0;
}
