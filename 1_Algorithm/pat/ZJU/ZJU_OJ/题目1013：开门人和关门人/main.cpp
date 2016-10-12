#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N,M;
	cin>>N;
	while(N--)
	{
		char arrid[20],leaid[20];
		char arrt[10]="24:00:00",leat[10]="00:00:00";	
		char s[100];
		cin>>M;
		while(M--)
		{			
			char temp[3][20];
			cin>>temp[0]>>temp[1]>>temp[2];

			if(strcmp(temp[1],arrt)<0)
			{
				strcpy(arrid,temp[0]);
				strcpy(arrt,temp[1]);
			}
			if(strcmp(leat,temp[2])<0)
			{
				strcpy(leaid,temp[0]);
				strcpy(leat,temp[2]);
			}
		}
		cout<<arrid<<" "<<leaid<<endl;
	}
	return 0;
}
