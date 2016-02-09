#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	char str[100];
	
	while(cin.getline(str,100,'\n'),str[0]!='#'){
		int len=strlen(str);
		for(int i=0;i<len;i++){
			switch(str[i]){
				case ' ':
					cout<<"%20";
					break;
				case '!':
					cout<<"%21";
					break;
				case '$':
					cout<<"%24";
					break;
				case '%':
					cout<<"%25";
					break;
				case '(':
					cout<<"%28";
					break;
				case ')':
					cout<<"%29";
					break;
				case '*':
					cout<<"%2a";
					break;
				default:
					printf("%c",str[i]);
					break;
			}
		}
		cout<<endl;
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
