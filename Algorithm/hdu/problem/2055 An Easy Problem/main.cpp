#include <iostream>
#include<cstdio>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int f[200];
	for(int i='A';i<='Z';i++)
	{
		f[i]=i-'A'+1;
	}
	
	for(int i='a';i<='z';i++)
	{
		f[i]=i-'a'+1;
		f[i]*=(-1);
	}
	
	int T;
	cin>>T;
	while(T--)
	{
		char x;
		int y;
		cin>>x>>y;
		cout<<f[x]+y<<endl;
	}
	
	
	return 0;
}
