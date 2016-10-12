#include <iostream>
#include<vector>
#include<cstdio>
using namespace std;


typedef struct Node
{
	int num;
	int sum;
	int start;
}Node;

std::vector<Node > sum;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	int k;
	while(cin>>k)
	{
		sum.resize(k);
		for(int i=0;i<k;i++)
			cin>>sum[i].num;
		sum[0].start=0;
		sum[0].sum=sum[0].num;
		
		for(int i=1;i<k;i++)
		{
			if(sum[i-1].sum>=0)
			{
				sum[i].start=sum[i-1].start;
				sum[i].sum=sum[i-1].sum+sum[i].num;
			}
			else
			{
				sum[i].start=i;
				sum[i].sum=sum[i].num;
			}
		}
		
		int mmax=sum[0].sum;
		int index=0;
		for(int i=1;i<k;i++)
		{
			if(sum[i].sum>mmax)
			{
				mmax=sum[i].sum;
				index=i;
			}
		}
		if(mmax<0)printf("0 %d %d\n",sum[0].num,sum[k-1].num);
		else printf("%d %d %d\n",sum[index].sum,sum[sum[index].start].num,
						sum[index].num);
	}
	return 0;
}
