
#include<iostream>//贪心
#include<cstdio>//题目意思：是老鼠用m克猫粮和猫兑换自己喜欢的食物，但是老鼠喜欢的食物在许多仓库并且每层仓库的兑换率都不相同但是每层的兑换率是J[i]克猫粮兑F[i]食物（i是层数）
#include<cstring>
const int MAX=10001;
int J[MAX];
int F[MAX];
double p[MAX];
using namespace std;
int main()
{
	int m,n,k;
	int i;
	double sum;
	int max;
	while(cin>>m>>n,m!=-1||n!=-1 )
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			cin>>J[i]>>F[i];
			if(F[i]==0)//不用换的时候··直接就去哪了。性价比无穷大 
			{
				p[i]=0;
				sum+=J[i];
			}
			else
			{
				p[i]=(double)J[i]/F[i];
			}
				
		}
		k=n;
		while(n!=0&&m!=0)
		{
			max=1;
			for(i=2;i<=k;i++)
			{
				if(p[max]<p[i])
				{
					max=i;
				}
			}
			if(m<=F[max])
			{
				sum+=(m*p[max]);
				p[max]=0;
				m=0;
			}
			else
			{
				sum+=J[max];
				m-=F[max];
				p[max]=0;
			}
			n--;
		}
		printf("%.3f\n",sum);
	}
    return 0;
}
