#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N,M,G;
	int score[11];
	char stuid[1000][20];
	int stuG[1000];
	while(cin>>N,N)
	{
		memset(stuG,0,sizeof(stuG));
		cin>>M>>G;
		for(int i=1;i<=M;i++)
			cin>>score[i];
		for(int i=1;i<=N;i++)
		{
			int pnum=0;
			int s[11];
			cin>>stuid[i]>>pnum;
			for(int j=1;j<=pnum;j++)
			{
				cin>>s[j];
				stuG[i]+=score[s[j]];
			}
		}
		
		int count=0;
		for(int i=1;i<=N;i++)
		{
			if(stuG[i]>=G)count++;
		}
		cout<<count<<endl;
		int si;
		for(int i=1;i<=N;i++)
		{
			si=1;
			for(int j=1;j<=N;j++)
			{
				if(stuG[j]>stuG[si])
				{
					si=j;
				}
				else if(stuG[j]==stuG[si])
				{
					if(strcmp(stuid[j],stuid[si])<0)
					{
						si=j;
					}
				}
			}
			if(stuG[si]>=G)
				cout<<stuid[si]<<" "<<stuG[si]<<endl;
			else break;
			stuG[si]=0;
		}
	}
	return 0;
}
