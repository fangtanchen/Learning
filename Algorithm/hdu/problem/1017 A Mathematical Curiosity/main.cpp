#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	
	int N;
	cin>>N;
	//cout<<endl;
	while(N)
	{
		int cnt=1;//注意位置，吃亏了 
		while(cin>>n>>m,n||m)
		{
			//int cnt=1;
			int a,b;
			int maxa = n-1;//注意，n-1和n-2是判断条件的<和《= 
			int count=0;
			for(a=1;a<maxa;a++)// 
			{
				int k=a*a;
				for(b=a+1;b<n;b++)
				{
					if(!((k+b*b+m)%(a*b)))count++;
					//注意   !k%m与!(k%m)  的区别 
				}
			}
			printf("Case %d: %d\n",cnt++,count);
		}
		
		N--;
		if(N)cout<<endl;
	}
	//cout<<"fadf"<<endl;
	return 0;
}
