#include <iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int T;
	cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		char A[1010];
		char B[1010];
		char C[1010];
		cin>>A>>B;
		printf("Case %d:\n",ti);
		cout<<A<<" + "<<B<<" = ";				
		int Alen=strlen(A);
		int Blen=strlen(B);
		int carry=0;
		int Clen=Alen>Blen?Alen:Blen;
		int ci=Clen-1;
		int ai,bi;
		for(ai=Alen-1,bi=Blen-1;ai>=0&&bi>=0;ai--,bi--)
		{
			int temp=A[ai]+B[bi]-'0'+carry-'0';
			carry=temp/10;
			C[ci]=temp%10+'0';
			ci--;
		}
		while(ai>=0)
		{
			int temp=A[ai]-'0'+carry;
			carry=temp/10;
			C[ci]=temp%10+'0';
			ci--;
			ai--;
		}
		while(bi>=0)
		{
			int temp=B[bi]-'0'+carry;
			carry=temp/10;
			C[ci]=temp%10+'0';
			ci--;
			bi--;
		}
		C[Clen]=0;
		if(carry)cout<<carry;		
		cout<<C<<endl;
		if(ti!=T)printf("\n");
	}
	return 0;
}
