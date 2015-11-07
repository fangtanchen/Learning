#include <iostream>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Time
{
	int begin;
	int end;
};


void sort(struct Time* T,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(T[i].end>T[j].end)
			{
				struct Time temp;
				temp.begin=T[i].begin;
				temp.end=T[i].end;
				T[i].begin=T[j].begin;
				T[i].end=T[j].end;
				T[j].begin=temp.begin;
				T[j].end=temp.end;
			}
		}
	}
}

int max(int x,int y)
{
	return (x>y)?x:y;
}

int main(int argc, char** argv) {
	int n;
	struct Time time[100];
	int A[100][100];
	int count[100];
	while(cin>>n,n)
	{
		memset(count,0,sizeof(count));
		memset(A,0,sizeof(A));
		for(int ni=0;ni<n;ni++)
		{
			cin>>time[ni].begin>>time[ni].end;
		}
		
		sort(time,n);
		
		//建图，A[i][0]表示结束时间，A[i][j]表示开始时间，count【k】记录相应的个数 
		int k=0;
		A[0][0]=time[0].end;
		for(int i=0;i<=n-2;i++)
		{
			count[k]++;
			A[k][count[k]]=time[i].begin;
			if(time[i].end!=time[i+1].end)
			{
				k++;
				A[k][0]=time[i+1].end;
			}
		}
		count[k]++;
		A[k][count[k]]=time[n-1].begin;
		
		//cout<<"dsaf"<<endl;
		int f[100]={0};//f[i]表示结束时间为A[i][0]时的最大完整节目数
		for(int i=0;i<=k;i++)
		{
			if(i>0)f[i]=f[i-1];
			for(int j=1;j<=count[i];j++)
			{
				int k=0;
				for(;A[k][0]<=A[i][j];k++);
				k--;
				if(k>=0)//开始时间前有节目结束的话 
				{
					f[i]=max(f[i],f[k]+1);
				}
				else
				{
					f[i]=1;			
				}
			}
		} 
		
		cout<<f[k]<<endl;
		
	}
	return 0;
}
