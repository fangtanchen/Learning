#include<stdio.h>
//#include<iostream>
//using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	char a[20][1000],b[20][1000],sum[20][1000];
	int i =0;
	int j=0;
	if(t<1||t>20)return 0;
	
	int flag=0;
	int k=0;
	while(i<t)
	{	
		j=0;
		if(2==scanf("%s %s",a[i],b[i]))
		{
			while(j<)
			{
				k=(a[i][j]+b[i][j]-96+flag);
				flag=k%10;
				sum[i][j]=flag+48;
				j++;
			}
		}
		i++;
	}
	for(i=0;i<t;i++)
	{
		printf("Case %d:\n",i+1);
		printf("%s + %s = %s\n\n",a[i],b[i],sum[i]);
	}
	
	return 0;
}