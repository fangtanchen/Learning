#include <iostream>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	int P[111];
	char T[6][111][10];
	int count[6];
	int K[6][111];
	while(cin>>N,N>=0)
	{
		memset(count,0,sizeof(count));
		memset(K,0,sizeof(K));
		for(int i=0;i<N;i++)
		{
			cin>>P[i];
			cin>>T[P[i]][count[P[i]]++];		
		}
		
		//Ìø³öÇ°1/2
		for(int i=1;i<6;i++) 
		{
			for(int j=count[i]/2;j>=1;j--)
			{
				int ki=0;
				for(int k=1;k<count[i];k++)
				{
					if(strcmp(T[i][k],T[i][ki])<0)
							ki=k;
				}
				K[i][ki]=1;
				strcpy(T[i][ki],"25:00:00");
			}
		}
		
		memset(count,0,sizeof(count));
		
		for(int i=0;i<N;i++)
		{
			int score=0;
			switch(P[i])
			{
				case 0:
					cout<<"50"<<endl;
					break;
				case 1:
					score=60+K[1][count[1]]*5;
					count[1]++;
					cout<<score<<endl;
					break;
				case 2:
					score=70+K[2][count[2]]*5;
					count[2]++;
					cout<<score<<endl;
					break;
				case 3:
					score=80+K[3][count[3]]*5;
					count[3]++;
					cout<<score<<endl;
					break;
				case 4:
					score=90+K[4][count[4]]*5;
					count[4]++;
					cout<<score<<endl;
					break;
				case 5:
					score=100;				
					cout<<score<<endl;
					break;
				default:
					break;
			}
		}
		cout<<endl;
	}
	return 0;
}
