#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int main(){
	char str[500];
	while(cin.getline(str,500,'\n')&&(str[0]!='#')){
		int sum=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]!=' ')sum=sum+(i+1)*(str[i]-64);
		}
		printf("%d\n",sum);
	}
	return 0;
}
