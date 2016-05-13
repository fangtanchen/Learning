#include <iostream>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[101];
	while(gets(s))
	{
		int len=strlen(s);
		puts(s);
	}
	
	return 0;
}
