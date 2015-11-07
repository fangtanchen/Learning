#include <iostream>
#include<string>
#include<string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char a[20][1000],b[20][1000];
	char c[20][1000]={{0}};
	int flag[21]={0};
	int ti=0;
	cin>>ti;
	int t=0;
	while(t<ti)
	{
		int max,min;
		int ai=0,d=0;
		cin>>a[t]>>b[t];
		if(strlen(a[t])>strlen(b[t]))
		{
			max=strlen(a[t]);
			min=strlen(b[t]);
			ai=1;
		}
		else
		{
			max=strlen(b[t]);
			min=strlen(a[t]);
		}
		d=max-min;
	//	cout<<max<<endl<<min<<endl;
		//cout<<a<<endl;		
		int i=0;
		int temp = 0;
		c[t][max]=0;
		for(i=max-1;i>=d;i--)
		{
			if(ai)
			{	
				temp = flag[t] +a[t][i]+b[t][i-d]-48;
			}
			else
			{
				temp = flag[t] +a[t][i-d]+b[t][i]-48;
			}
			flag[t] = (temp)/58;
			if(flag[t])
				{
					c[t][i]=temp-10;
				}
				else
				{
					c[t][i]=temp;
				}
		} 
		
		if(ai)
		{
			for(i=d-1;i>=0;i--)
			{
				temp = a[t][i]+flag[t];	
				flag[t] = temp/58;
				if(flag[t])
				{
					c[t][i]=temp-10;
				}
				else
				{
					c[t][i]=temp;
				}
			}
		}
		else
		{
			for(i=d-1;i>=0;i--)
			{
				temp = b[t][i]+flag[t];
				flag[t] = temp/58;
				if(flag[t])
				{
					c[t][i]=temp-10;
				}
				else
				{
					c[t][i]=temp;
				}
			}
		}	
		t++;
	}
	int i=0;
	int k = ti-1;
	for(;i<ti;i++)
	{
		cout<<"Case "<<i+1<<":"<<endl;
		cout<<a[i]<<" + "<<b[i]<<" = ";
		if(flag[i])cout<<flag[i];
		cout<<c[i]<<endl;
		if(i!=k)cout<<endl;
	}
	return 0;
}
