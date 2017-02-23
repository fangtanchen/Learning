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
const int MAXN=1e6;

char str[2][MAXN];
int l[2],r[2];
bool flag[2];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        bool pos[2];
        while(EOF!=scanf("%s%s",str[0],str[1])){
            for(int ki=0;ki<2;ki++){
                pos[ki]=true;
                int len=strlen(str[ki]);
                int pi=0;
                if(str[ki][pi]=='-')pos[ki]=false,pi++;
                else if(str[ki][pi]=='+')pi++;

                for(;str[ki][pi]=='0';pi++)
                    ;
                l[ki]=pi;r[ki]=len-1;
                bool flag=false;
                for(int i=l[ki];i<len;i++){
                    if(str[ki][i]=='.'){
                        flag=true;
                        break;
                    }
                }
                if(flag){
                     for(pi=len-1;str[ki][pi]=='0';pi--)
                         ;
                     if(str[ki][pi]=='.')pi--;
                     r[ki]=pi;
                }
                str[ki][r[ki]+1]=0;
                if(r[ki]<l[ki]){
                     r[ki]=l[ki];
                     str[ki][l[ki]]='0';
                     str[ki][r[ki]+1]=0;
                     pos[ki]=true;
                }
            }
            bool flag=true;
            if((l[0]>r[0]&&(l[1]>r[1]))
                    ||((pos[0]==pos[1])
                        &&(strcmp(str[0]+l[0],str[1]+l[1])==0)))
                puts("YES");
            else puts("NO");

        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
