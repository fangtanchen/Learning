#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	while(cin>>N)
	{
		int A[100]={1,0};
		int B[100]={1,0};
		
		int Alen=1;
		for(int i=N+2;i<=2*N;i++)
		{
			int carry=0;
			for(int j=0;j<Alen;j++)
			{
				int temp=A[j]*i+carry;
				A[j]=temp%10000;
				carry=temp/10000;
			}
			if(carry)
			{
				A[Alen]=carry;
				Alen++;
			}
		}
		
		for(int i=2;i<=N;i++)
		{
			int carry=0;
			for(int j=Alen-1;j>=0;j--)
			{
				int temp=A[j]+carry*10000;
				A[j]=temp/i;
				carry=temp%i;
			}
			if(!A[Alen-1])Alen--;
		}
		
		printf("%d",A[Alen-1]);
		for(int i=Alen-2;i>=0;i--)				
		{
			printf("%04d",A[i]);
		}
		printf("\n");
	}
	return 0;
}
