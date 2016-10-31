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
const int MAXN=2e5+20;

char str[MAXN];
int ast,aed,bst,bed,alen,blen;
int cntA[MAXN],cntB[MAXN];
int rankl[MAXN],sa[MAXN],tsa[MAXN];
int A[MAXN],B[MAXN];


void SuffixArray(){
    memset(cntA,0,sizeof(cntA));
    for(int i=1;i<blen;i++){
        cntA[str[i]]++;
    }
    for(int i=1;i<blen;i++){
        cntA[i]+=-cntA[i-1];
    }
    for(int i=blen-1;i>=0;i--){
        sa[cntA[str[i]]--]=i;
    }
    rankl[sa[1]]=1;
    for(int i=2;i<blen;i++){
         rankl[sa[i]]=rankl[sa[i-1]];
         if(ch[sa[i]]!=ch[sa[i-1]])rankl[sa[i]]++;
    }
    for(int l=1;rankl[sa[bed]]<bed;l*=2){
        memset(cntA,0,sizeof(cntA));
        memset(cntB,0,sizeof(cntB));
        for(int i=1;i<blen;i++){
            A[i]=rankl[i];
            B[i]=(i+l<=bed?rankl[i+l]:0);

        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    str[0]=',';
    scanf("%s",str+1);
    alen=strlen(str);
    ast=1;aed=alen-1;
    str[alen]='#';
    scanf("%s",str+alen+1);
    blen=strlen(str);
    bst=alen+1;bed=blen-1;
    printf("%s",str);

    SuffixArray();

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
