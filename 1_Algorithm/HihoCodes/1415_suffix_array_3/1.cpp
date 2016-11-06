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
int height[MAXN];


void SuffixArray(){
    memset(cntA,0,sizeof(cntA));
    for(int i=1;i<=bed;i++){
        cntA[str[i]]++;
    }
    for(int i=1;i<=bed;i++){
        cntA[i]+=cntA[i-1];
    }
    for(int i=bed;i>=1;i--){
        sa[cntA[str[i]]--]=i;
    }
    rankl[sa[1]]=1;
    for(int i=2;i<=bed;i++){
         rankl[sa[i]]=rankl[sa[i-1]];
         if(str[sa[i]]!=str[sa[i-1]])rankl[sa[i]]++;
    }
    for(int l=1;rankl[sa[bed]]<bed;l*=2){
        memset(cntA,0,sizeof(cntA));
        memset(cntB,0,sizeof(cntB));
        for(int i=1;i<blen;i++){
            A[i]=rankl[i];
            B[i]=(i+l<=bed?rankl[i+l]:0);
            cntA[A[i]]++;
            cntB[B[i]]++;
        }
        for(int i=1;i<=bed;i++){
             cntA[i]+=cntA[i-1];
             cntB[i]+=cntB[i-1];
        }
        for(int i=bed;i>=1;i--){
             tsa[cntB[B[i]]--]=i;
        }
        for(int i=bed;i;i--){
            sa[cntA[A[tsa[i]]]--]=tsa[i];
        }
        rankl[sa[1]]=1;
        for(int i=2;i<=bed;i++){
            rankl[sa[i]]=rankl[sa[i-1]];
            if(A[sa[i]]!=A[sa[i-1]]||B[sa[i]]!=B[sa[i-1]])
                rankl[sa[i]]++;
        }
    }

    for(int i=1,j=0;i<=bed;i++){
        if(j) j--;
        while(str[i+j]==str[sa[rankl[i]-1]+j])
            j++;
        height[rankl[i]]=j;
    }
}


bool Check(int K){
    int minsa,maxsa;
    for(int i=1;i<=bed;i++){
        if(height[i]<K){
            minsa=sa[i];
            maxsa=sa[i];
        }else{
            minsa=min(minsa,sa[i]);
            maxsa=max(maxsa,sa[i]);
            if(maxsa-minsa>=K){
                if(minsa<=aed&&maxsa>=bst){
                    return true;
                }
            }
        }
    }
    return false;
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
//    printf("%s",str);

    SuffixArray();
    int l=0,r=blen;
    while(l<=r){
         int mid=(l+r)/2;
         if(Check(mid)){
             l=mid+1;
         }else{
             r=mid-1;
         }
    }
    printf("%d\n",l-1);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
