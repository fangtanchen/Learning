#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



#ifndef ONLINE
#pragma warning(disable:4996)
#endif

int main(int argc, char** argv) {
	#ifndef DEBUG_NOW
		freopen("in1.txt","r",stdin);
		//freopen("in.txt","w",stdout);
		freopen("out.txt","w",stdout);
	#endif
	char s[50][20];
	int si=0;
	for(si=0;!cin.eof();si++){
		cin.getline(s[si],50,'\n');
	}
	for(int i=0;i<si;i++){
		for(int j=0;j<si;j++){
			//cout<<s[i]<<" "<<s[j]<<endl;
			if(i<j)cout<<"Black wins."<<endl;
			else if(i==j)cout<<"Tie."<<endl;
			else {
				cout<<"White wins."<<endl;
			}
		}
	}
	#ifndef DEBUG_NOW
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif
	return 0;
}
