#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char str[10][10]={"zero","one","two","three","four",
				"five","six","seven","eight","nine"};
int main(int argc, char** argv) {
	
	char a;
	while((EOF!=scanf("%1c",&a)))
	{		
		int sum=0;
		sum+=(a-'0');
		while((EOF!=scanf("%1c",&a))&&(a!='\n'))
			sum+=(a-'0');
		int p=1000;
		if(!sum)
		{
			cout<<str[0]<<endl;
			continue;
		}
		while(p)
		{
			int t=sum/p;
			if(t)
			{				
				sum%=p;
				cout<<str[t];
				p/=10;
				break;
			}
			p/=10;
		}
		while(p)
		{
			int t=sum/p;
			sum%=p;
			cout<<" "<<str[t];
			p/=10;
		}
		cout<<endl;
	}
	
	return 0;
}
