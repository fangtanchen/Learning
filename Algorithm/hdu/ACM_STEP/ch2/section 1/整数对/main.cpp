#include <iostream>
#include<cmath>
#include<algorithm>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int res[100];

int solve(int n)
{
	int count=0;
	int a,b,c;
	for(int p=1;p<=n;p*=10)
	{
		a=(n/p)/11;
		b=(n/p)%11;
		if(b<10&&a+b!=0)
		{
			c=n-(11*a+b)*p;
			if(0==c%2)	
				res[count++]=a*p*10+b*p+c/2;
		}
		b--;
		if(b>=0&&a+b!=0)
		{
			c=n-(11*a+b)*p;
			if(0==c%2)
				res[count++]=a*p*10+b*p+c/2;
		}
		
	}
	return count;
}

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		if(!n)break;
		int count=solve(n);
		if(!count)
			cout<<"No solution."<<endl;
		else
		{
			sort(res+0,res+count);
			for(int i=0;i<count-1;i++)
				if(res[i]!=res[i+1])
					cout<<res[i]<<" ";
			cout<<res[count-1]<<endl;
		}
	}
	return 0;
}
