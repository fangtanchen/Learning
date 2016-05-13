#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char cmd[4][15]={"Pop","Push","PeekMedian"};
int cmp(char* c)
{
	int i=0;
	strcpy(cmd[3],c);
	while(strcmp(cmd[i],c))
		i++;
	return i;
}
int num[100004];
int numi=0;
int rk[100004];
int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		//memset(rk,1,sizeof(rk));
		while(n--)
		{
			char s[20];
			cin>>s;
			switch(cmp(s))
			{
				case 0:
					if(numi==0)cout<<"Invalid"<<endl;
					else {						
						numi--;						
						cout<<num[numi]<<endl;
						int temp=num[numi];
						for(int i=0;i<numi;i++)
						{
							if(num[i]>temp)
							{
								rk[i]--;
							}
						}
					//	rk[numi]=1;
					}
					break;
				case 1:
					int temp;
					cin>>temp;
					num[numi]=temp;
					rk[numi]=1;
					for(int i=0;i<=numi;i++)
					{
						if(num[i]>temp)
							rk[i]++;
						else if(num[i]<temp)
							rk[numi]++;								
					}
					numi++;
					break;
				case 2:
					if(numi){					
						int ans=0;
						int t;
						if(numi%2)t=(numi+1)/2;
						else t=numi/2;
						for(ans=0;rk[ans]!=t;ans++);
						cout<<num[ans]<<endl;
					}
					else cout<<"Invalid"<<endl;
					break;
				default:
					break;
			}
		}
	}
	return 0;
}
