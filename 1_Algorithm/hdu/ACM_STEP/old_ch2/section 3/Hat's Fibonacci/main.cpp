#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int F[7050][510];
int len[7050];
void Solve()
{
	memset(F,0,sizeof(F));
	memset(len,1,sizeof(len));
	F[1][0]=F[4][0]=F[2][0]=F[3][0]=1;
	len[1]=len[2]=len[3]=len[4]=1;
	for(int i=5;i<7050;i++)
	{
		int carry=0;
		int maxLen=len[i-1];
		len[i]=maxLen;
		for(int j=0;j<maxLen;j++)
		{
			int temp=F[i-4][j]+F[i-2][j]+F[i-3][j]+F[i-1][j]+carry;
			F[i][j]=temp%10000;
			carry=temp/10000;
		}
		if(carry)
		{
			F[i][maxLen]=carry;
			len[i]++;
		}
	}
}
int main(int argc, char** argv) {
	int n;	
	Solve();
/*	for(int i=1;i<20;i++)
		cout<<len[i]<<"   ";
	cout<<len[7049]<<endl;*/
	while(cin>>n)
	{
		printf("%d",F[n][len[n]-1]);
		for(int i=len[n]-2;i>=0;i--)
		{
			printf("%04d",F[n][i]);
		}
		cout<<endl;
	}
	return 0;
}
