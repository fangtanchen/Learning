#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char a[3];
	while(scanf("%c%c%c",&a[0],&a[1],&a[2])!=EOF)
	//while(scanf("%s",a))
	{
		getchar();
		for(int i=0;i<2;i++)
		{
			for(int j=i+1;j<3;j++)
			{
				if(a[i]>a[j])
				{
					char temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		for(int i=0;i<2;i++)
		{
			printf("%c ",a[i]);
		}
		printf("%c\n",a[2]);
	}
	return 0;
}
