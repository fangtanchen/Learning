#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	int s[111]={0};
	while(cin>>N,N)
	{
		int sum=0;
		for(int i=1;i<=N;i++)
			cin>>s[i];
		for(int i=1;i<=N;i++)
		{
			int t=s[i]-s[i-1];
			if(t<0)sum-=4*t;
			else sum+=6*t;
			sum+=5;
		}
		cout<<sum<<endl;
	}
	return 0;
}
