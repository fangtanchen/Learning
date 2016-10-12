#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char c[26];
int a[27];
int len;

int max1[6],min1[6];
int t[6];
int dfs(int cnt,int target)
{
	int i,j;
	int temp=1;
	int flag=0;
	int temp_target=target;
	if(!cnt)return !target;//cnt==0是结束 
	if(target<min1[cnt]||target>max1[cnt])return 0;
	
	for(i=1;i<=len;i++)
	{
		flag =0;
		t[cnt]=i;
		temp=1;//这个一定要记得。以后在哪里有什么变量，就在哪里定义。运行不通过再把定义上提
		for(j=5-cnt;j>0;j--)
		{
			if(t[cnt]==t[cnt+j])
			{
				flag = 1;
				break;
			}
		}
		if(flag)continue;
		temp_target=target;
		for(j=1;j<=cnt;j++)
		{
			temp*=a[i];
		}
		if(!(cnt%2))temp*=-1;
		temp_target -=temp;
		if(dfs(cnt-1,temp_target))return 1;
	}
	return 0;
}

int main(int argc, char** argv) {
	int count = 5;
	int i,j;
	int temp;
	int target;
	while(cin>>target,cin>>c,target||strcmp("END",c))
	{
		memset(t,0,sizeof(t));
		len = strlen(c);
		for(i=0;i<len;i++)
			a[i+1]=c[i]-64;
		for(i=1;i<=len;i++)
		{
			for(j=i+1;j<=len;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
				
			}
		}	
		
		count = 5;
		max1[1]=a[len];
		min1[1]=a[1];
		min1[2]=-a[len]*a[len]+a[1];
		max1[2]=-a[1]*a[1]+a[len];
		max1[3]= a[len]*a[len]*a[len]-a[1]*a[1]+a[len-1];
		min1[3]=a[1]*a[1]*a[1]-a[len]*a[len]+a[2];
		max1[4]=-a[1]*a[1]*a[1]*a[1]+a[len]*a[len]*a[len]-a[2]*a[2]+a[len-1];
		min1[4]=-a[len]*a[len]*a[len]*a[len]+a[1]*a[1]*a[1]-a[len-1]*a[len-1]+a[2];
		min1[5]=a[1]*a[1]*a[1]*a[1]*a[1]-a[len]*a[len]*a[len]*a[len]
		+a[2]*a[2]*a[2]-a[len-1]*a[len-1]+a[3];
		max1[5]=a[len]*a[len]*a[len]*a[len]*a[len]-a[1]*a[1]*a[1]*a[1]
		+a[len-1]*a[len-1]*a[len-1]-a[2]*a[2]+a[len-2];
		if(dfs(count,target))
		{
			printf("%c%c%c%c%c\n",a[t[1]]+64,a[t[2]]+64,a[t[3]]+64,a[t[4]]+64,a[t[5]]+64);
		}
		else
		{
			printf("no solution\n");
		}
	}
	
	return 0;
}