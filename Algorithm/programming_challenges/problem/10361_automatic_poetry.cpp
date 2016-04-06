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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n;
    char in[2][120];
    char s[6][120];
    scanf("%d",&n);
    getchar();
    for(int ni=0;ni<n;ni++){
        int len[2];
        for(int i=0;i<2;i++){
            cin.getline(in[i],120,'\n');
            len[i]=strlen(in[i]);
        }
        int slen[6];
        memset(slen,0,sizeof(slen));
        memset(s,0,sizeof(s));
        int si=1,ti=0;
        for(int i=0;i<len[0];i++){
            if(in[0][i]=='<'||
                    in[0][i]=='>'){
                si++;
                continue;
            }
            s[si][slen[si]++]=in[0][i];
            putchar(in[0][i]);
        }
        putchar('\n');
        for(int i=0;i<len[1];i++){
             if(in[1][i]=='.')break;
             putchar(in[1][i]);
        }
        printf("%s%s%s%s\n",s[4],s[3],s[2],s[5]);

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
