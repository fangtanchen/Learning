#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	while(EOF!=scanf("%d%d",&n,&m))
	{
		cout<<"+";
		for(int i=0;i<n;i++)
			cout<<"-";
		cout<<"+"<<endl;
		
		for(int j=0;j<m;j++)
		{
			cout<<"|";
			for(int i=0;i<n;i++)cout<<" ";
			cout<<"|"<<endl;
		}
		
		cout<<"+";
		for(int i=0;i<n;i++)
			cout<<"-";
		cout<<"+"<<endl<<endl;
	}
	return 0;
}
