#include <iostream>
#include<cstdio>
//题目做错了，可能有多个长度最小的，但是他们的重量不是最小的 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int l[5010],w[5010];
int n;
int f()
{
	int minli=0,minwi=0;
	for(int i=0;i<n;i++)
	{
		if(l[minli]>l[i]||
		((l[minli]==l[i])&&(w[minli]>w[i])))minli=i;
		if(w[minwi]>w[i]||
		((w[minwi]==w[i])&&(l[minwi]>l[i])))minwi=i;
	}
	
	if(l[minli]==100000)return 0;
	
	if((w[minli]==w[minwi])
	||(l[minli]==l[minwi]))
		return 1;	
		
	
	for(int i=0;i<n;i++)
	{
		if(l[i]!=100000)
		{		
			if((l[i]>=l[minli]&&w[i]>=w[minli])
			|| (l[i]>=l[minwi]&&w[i]>=w[minwi]))
			{
				l[i]=100000;
				w[i]=100000;
			}							
		}		
	}
	return 2+f();
	
}

int main(int argc, char** argv) {
	int T;
	cin>>T;
	
	while(T--)
	{		
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>l[i]>>w[i];
		int time=f();
		cout<<time<<endl;	
	}
	return 0;
}
