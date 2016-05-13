#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int in[10],out[10],stack[10]={100};//stack[0]要是out取不到的值，否则可能会因此而引起问题 
	int op[30]={0};
	while(scanf("%d",&n)!=EOF)
	{
		memset(op,0,sizeof(op));
		for(int i=1;i<=n;i++)
		{
			scanf("%1d",&in[i]);
		}

		for(int i=1;i<=n;i++)
		{
			scanf("%1d",&out[i]);
		}
		
		int ini,outi,stacki,opi;
		ini = outi=stacki=1;
		opi=1;
		while(outi<=n&&ini<=n)
		{
			stack[stacki]=in[ini];
			opi++;
			while(stack[stacki]==out[outi])
			{
				stacki--;
				outi++;
				op[opi]=1;
				opi++;
			}
			ini++;
			stacki++;
		}
		if(outi>n)
		{
			cout<<"Yes."<<endl;
			opi--;
			for(int i=1;i<=opi;i++)
				if(op[i])cout<<"out"<<endl;
				else cout<<"in"<<endl;			
		}
		else
		{
			cout<<"No."<<endl;
		}
		cout<<"FINISH"<<endl;	
	}
	
	
	return 0;
}
