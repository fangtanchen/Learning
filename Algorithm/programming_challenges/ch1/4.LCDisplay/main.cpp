#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAXLENGTH 8

int main(int argc, char** argv) {
	string digit[5][10]={
	" - ","   "," - "," - ","   "," - "," - "," - "," - "," - ",
	"| |","  |","  |","  |","| |","|  ","|  ","  |","| |","| |",
	"   ","   "," - "," - "," - "," - "," - ","   "," - "," - ",
	"| |","  |","|  ","  |","  |","  |","| |","  |","| |","  |",
	" - ","   "," - "," - ","   "," - "," - ","   "," - "," - "
	};
	int n,s;
	while(cin>>s>>n&&(s||n)){
		char nstr[14];
		sprintf(nstr,"%d",n);
		int nlen=strlen(nstr);
		int rmax=2*s+3;
		for(int ri=0;ri<rmax;ri++){
			string output;
			for(int i=0;i<nlen;i++){
				int dig=nstr[i]-'0';
				if(ri==0)  output=digit[0][dig];
				if(ri>=1&&ri<=s) output=digit[1][dig];
				if(ri==s+1) output=digit[2][dig];
				if(ri>=s+2&&ri<=2*s+1) output=digit[3][dig];
				if(ri==2*s+2) output=digit[4][dig];
				
				printf("%c",output[0]);
				for(int ki=0;ki<s;ki++){
					printf("%c",output[1]);
				}
				printf("%c",output[2]);
				if(i<nlen-1)cout<<" ";
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
