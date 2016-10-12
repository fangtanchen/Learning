#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int flag[21];
int a[21];
int n;
int global_t;
bool prime(int x)
{
	int i;
	int t = x/2;
	for(i=2;i<=t;i++)
	{
		if(!(x%i))return 0;
	}
	return 1;
}

void dfs(int num, int cnt)
{
	flag[num]=1;
	a[cnt]=num;
	
	int odd = num%2+1; //�������������Ļ�����ȥ����֦ ��������ż���Ļ�����ȥż��֦ 
	if(cnt==n)
	{
		//printf("Case %d:\n",global_t);
		if(prime(num+1))
		{
			int i;
			for(i=1;i<n;i++)
			{
				printf("%d ",a[i]);
			}
			printf("%d\n",a[n]);
		}
	}
	else
	{
		int i;
		//for(i=1;i<=n;i+=1)
		for(i=odd;i<=n;i+=2)
		{
			if(flag[i])continue;
			if(prime(i+num))
			{
				dfs(i,cnt+1);
			}
		}
	}
	flag[num]=0;
}

int main(int argc, char** argv) {
	global_t=1;
	while(cin>>n)
	{
		
		memset(flag,0,sizeof(flag));
		//memset(a,0,sizeof(a));
		printf("Case %d:\n",global_t);
		if(n>1&&n%2)//���n����������ô��Ȼ ������������������Ϊż�������ܹ��ɻ� 
		{
			cout<<endl;
			continue;
		}
		dfs(1,1);
		cout<<endl;
		global_t++;
	}
	return 0;
}
