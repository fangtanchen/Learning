
#include<iostream>//̰��
#include<cstdio>//��Ŀ��˼����������m��è����è�һ��Լ�ϲ����ʳ���������ϲ����ʳ�������ֿⲢ��ÿ��ֿ�Ķһ��ʶ�����ͬ����ÿ��Ķһ�����J[i]��è����F[i]ʳ�i�ǲ�����
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
			if(F[i]==0)//���û���ʱ�򡤡�ֱ�Ӿ�ȥ���ˡ��Լ۱������ 
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
