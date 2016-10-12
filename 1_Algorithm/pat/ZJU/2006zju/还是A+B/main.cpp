#include <iostream>
#include<cstring> 
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fun(int x,int k)
{
	int t=1;
	while((k--))
	{
		t*=10;
	}
	return x%t;
}

int main(int argc, char** argv) {
	int a,b,k;
	while(cin>>a>>b>>k,a||b)
	{
		if(fun(a,k)==fun(b,k))cout<<-1<<endl;
		else cout<<a+b<<endl;
	}
	
	return 0;
}
