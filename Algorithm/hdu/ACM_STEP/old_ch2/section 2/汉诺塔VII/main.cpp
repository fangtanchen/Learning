#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int flag=0;

void dfs(int n,int* A,int* B,int* C)
{
	if(!n){
		flag=true;
		return;
	}
	if(B[0]&&n==B[1])
	{
		flag=false;
		return;
	}
	if(A[0]&&n==A[1])
	{
		A[1]=A[0]-1;
		dfs(n-1,++A,C,B);		
	}
	if(C[0]&&C[1]==n)
	{
		C[1]=C[0]-1;
		dfs(n-1,B,A,++C);
	}
	
}

int main(int argc, char** argv) {
	int T;
	cin>>T;	
	while(T--)
	{
		int N;
		cin>>N;
		int A[70],B[70],C[70];		
		cin>>A[0];
		for(int i=1;i<=A[0];i++)
			cin>>A[i];
		cin>>B[0];
		for(int i=1;i<=B[0];i++)
			cin>>B[i];
		cin>>C[0];
		for(int i=1;i<=C[0];i++)
			cin>>C[i];
		dfs(N,A,B,C);
		if(flag)cout<<"true"<<endl;
		else cout<<"false"<<endl;
		
	}
	return 0;
}
