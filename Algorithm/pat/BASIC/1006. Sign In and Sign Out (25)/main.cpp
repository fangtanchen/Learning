#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int m;
	while(cin>>m)
	{
		char begId[20],endId[20];
		char begt[10]="24:00:00",endt[10]="00:00:00";
		char id[20],at[10],lt[10];
		while(m--)
		{
			cin>>id>>at>>lt;
			if(strcmp(begt,at)>0)
			{
				strcpy(begt,at);
				strcpy(begId,id);
			}
			if(strcmp(endt,lt)<0)
			{
				strcpy(endt,lt);
				strcpy(endId,id);
			}
		}
		cout<<begId<<" "<<endId<<endl;
	}
	
	return 0;
}
