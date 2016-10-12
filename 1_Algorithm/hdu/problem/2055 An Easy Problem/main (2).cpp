#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int f[256];
	for(int i='A';i<='Z';i++)
	{
		f[i]=i-64;
	}
	for(int i='a';i<='z';i++)
	{
		f[i]=-1*i+'a'-1;
	}
	
	int t;
	cin>>t;
	int i=0;
	while(i++<t)
	{
		char x;
		int y;
		cin>>x>>y;
		cout<<f[x]+y<<endl;
		
	}
	return 0;
}
