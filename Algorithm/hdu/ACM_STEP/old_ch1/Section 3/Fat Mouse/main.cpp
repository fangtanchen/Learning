#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int M,N;
	int F[1010],J[1010];
	float D[1010];
	while(cin>>M>>N,M!=-1&&N!=-1)	
	{
		double total=0;
		for(int i=0;i<N;i++)
		{
			cin>>J[i]>>F[i];
			if(F[i]==0)
			{
				total+=J[i];
				D[i]=-1;
			}
			else D[i]=J[i]*1.0/F[i];
		}
		for(int i=0;i<N;i++)
		{
			int t=0;
			for(int j=0; j<N;j++)
			{
				if(D[j]>D[t])t=j;
			}
			if(D[t]==-1)break;
			else 
			{
				if(F[t]>=M)
				{
					total+=(J[t]*M*1.0/F[t]);
					break;
				}
				else
				{
					M-=F[t];
					total+=J[t];
					D[t]=-1;
				}
			}			
		}
		printf("%.3f\n",total);
	}
	return 0;
}
