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
		int cnt=1;//ע��λ�ã��Կ��� 
		while(cin>>n>>m,n||m)
		{
			//int cnt=1;
			int a,b;
			int maxa = n-1;//ע�⣬n-1��n-2���ж�������<�͡�= 
			int count=0;
			for(a=1;a<maxa;a++)// 
			{
				int k=a*a;
				for(b=a+1;b<n;b++)
				{
					if(!((k+b*b+m)%(a*b)))count++;
					//ע��   !k%m��!(k%m)  ������ 
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
