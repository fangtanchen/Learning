#include <iostream>
#include<cstdio>
#include<cstring>
using  namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char user_a[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int switcs(char* dig)
{
	int i=0;
	while(strcmp(dig,user_a[i]))
		i++;
	return i;
}

int main(int argc, char** argv) {
	char s[100];
	while(cin.getline(s,100))
	{
		int a[2]={0,0};
		int ai=0;
		int len=strlen(s);
		char temp[15];
		int tempi=0;
		for(int i=0;i<len;i++)
		{
			switch(s[i])
			{
				case ' ':
					if(0!=tempi){
						temp[tempi]=0;				
						int num=switcs(temp);
						a[ai]=a[ai]*10+num;					
						tempi=0;
					}
					break;
				case '+':
					ai++;
					tempi=0;
					break;
				case '=':
					break;
				default:
					temp[tempi++]=s[i];
					break;
			}
		}
		if(a[0]==0&&a[1]==0)		break;
		else cout<<a[0]+a[1]<<endl;
	}
	return 0;
}
