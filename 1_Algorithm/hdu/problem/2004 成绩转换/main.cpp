#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		if(n<0||n>100)
		{
			cout<<"Score is error!"<<endl;
			continue;
		}
		switch(n/10)
		{
			case 10:
			case 9:
				cout<<"A"<<endl;
				break;
			case 8:
				cout<<"B"<<endl;
				break;
			case 7:
				cout<<"C"<<endl;
				break;
			case 6:
				cout<<"D"<<endl;
				break;
			default:
				cout<<"E"<<endl;
				break;			
		}
	}
	return 0;
}
