#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	cin>>t;
	int A[55],B[55];
	while(t--)
	{
		int N;
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>A[i]>>B[i];
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(A[i]>A[j])
				{
					int t=A[i];
					A[i]=A[j];
					A[j]=t;
					t=B[i];
					B[i]=B[j];
					B[j]=t;					
				}
			}
		}
		for(int i=0;i<N;i++)
		{			
			for(int j=0;j<B[i];j++)
			{
				cout<<">+";
				for(int k=2;k<A[i];k++)
					cout<<"-";
				cout<<"+>"<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}
