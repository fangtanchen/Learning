#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAXC 256
char Reve[MAXC];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    Reve['A']='A'; Reve['E']='3';  Reve['H']='H'; Reve['I']='I';
    Reve['J']='L'; Reve['L']='J';  Reve['M']='M'; Reve['O']='O';
    Reve['S']='2'; Reve['T']='T';  Reve['U']='U'; Reve['V']='V';
    Reve['W']='W'; Reve['X']='X';  Reve['Y']='Y'; Reve['Z']='5';
    Reve['1']='1'; Reve['2']='S';  Reve['3']='E'; Reve['5']='Z';
    Reve['8']='8';
    char s[30];
    while(EOF!=scanf("%s",s)){
        printf("%s -- is ",s);
        int st=0, ed=strlen(s)-1;
        for(int i=0;i<=ed;i++){
            if(s[i]=='0'){
                s[i]='O';
            }
        }
        bool f1=true,f2=true;
        for(;st<=ed;st++,ed--){
            if(s[st]!=s[ed]){
                 f1=false;
            }
            if(Reve[s[st]]!=s[ed]){
                 f2=false;
            }
        }
        if(f1&&f2){
             printf("a mirrored palindrome.\n");
        }else if(f1){
            printf("a regular palindrome.\n");
        }else if(f2){
            printf("a mirrored string.\n");
        }else{
             printf("not a palindrome.\n");
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
