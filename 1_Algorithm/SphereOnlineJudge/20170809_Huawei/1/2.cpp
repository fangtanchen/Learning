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
const int MAXN=1e6+10;

char str[MAXN];
char in[MAXN];

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    int slen=0;
    scanf("%s",in);
    int inlen=strlen(in);
    for(int i=0;i<inlen;){
        while(in[i]!='x'&&in[i]!=0)i++;
        if(in[i]==0)break;
        i=i+1;
        int j=i+1;
        if(in[j]=='F'||in[i]==0)break;
        slen++;
        str[slen-1]=(in[j]-'0');
        if(i!=j){
            if(in[i]=='F'||in[i]==0)break;
            str[slen-1]*=10;
            str[slen-1]+=in[i]-'0';
        }
        i=j+1;

    }
    cout<<in<<endl;
    int st=0;
    for(st=0;st<slen;st++){
        if(str[st]!=0)break;
    }
    if(st==slen){
        printf("0\n");
        return 0;
    }
    printf("%d",str[st]);
    for(int i=st+1;i<slen-1;i++){
        printf("%02d",str[i]);
    }
    if(slen-1!=st)printf("%d",str[slen-1]);
    printf("\n");


#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //system("out.txt");
    #endif

    return 0;
}

