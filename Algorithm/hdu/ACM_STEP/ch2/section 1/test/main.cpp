#include <iostream>
#include <cstring>
#include<cstdio>
using namespace std;

int trans(char * str)
{
	char chara;
	chara = str[0];
	switch(chara)
	{
	case 'z':
		if(strcmp(str,"zero") == 0)
			return 0;
		else
			return -1;
		break;
	case 'o':
		if(strcmp(str,"one") == 0)
			return 1;
		else
			return -1;
		break;
	case 't':
		if(strcmp(str,"two") == 0)
			return 2;
		else if(strcmp(str,"three") == 0)
			return 3;
		else
			return -1;
		break;
	case 'f':
		if(strcmp(str,"four") == 0)
			return 4;
		else if(strcmp(str,"five") == 0)
			return 5;
		else
			return -1;
		break;
	case 's':
		if(strcmp(str,"six") == 0)
			return 6;
		else if(strcmp(str,"seven") == 0)
			return 7;
		else
			return -1;
		break;
	case 'e':
		if(strcmp(str,"eight") == 0)
			return 8;
		else
			return -1;
		break;
	case 'n':
		if(strcmp(str,"nine") == 0)
			return 9;
		else
			return -1;
		break;
	default:
		return -1;
	}
}

int op(char *opra)
{
	int i,j;
	char num1[10];
	char num2[10];
	int opr1,opr2;
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	i = j = 0;
	while(opra[i]!=' ' && opra[i] != 0)
	{
		num1[j] = opra[i];
		i++;
		j++;
	}
	i++;
	j = 0;
	while(opra[i]!=' ' && opra[i] != 0)
	{
		num2[j] = opra[i];
		i++;
		j++;
	}

	opr1 = trans(num1);
	opr2 = trans(num2);
	if(opr2 == -1)
		return opr1;
	else
		return opr1*10 + opr2;

}

int main()
{
	char str[50];
	char opra1[20];
	char opra2[20];
	int num1,num2;
	int result;
	int i,j,k;
	while(1)
	{
		memset(str,0,sizeof(str));
		memset(opra1,0,sizeof(opra1));
		memset(opra2,0,sizeof(opra2));
		gets(str);
		i=0;
		while(str[i]!='+')
			i++;
		strncpy(opra1,str,i-1);
		k = 0;
		for(j=i+2;str[j]!='=';j++)
			opra2[k++] = str[j];
		result = 0;
		//cout<<opra1<<endl;
		//cout<<opra2<<endl;
		num1 = op(opra1);
		num2 = op(opra2);
		if(num1 == 0 && num2 == 0)
			break;
		result = num1 + num2;
		cout<<result<<endl;
	}
	return 0;
}
