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

int t1[]={1,1,2,6,4,2,2,4,2,8};
int t2[]={6,6,2,6,4,4,4,8,4,6};
int circ[]={6,8,4,2};


int F(char* str){
    int len=strlen(str);
    if(len<2){
        return t1[str[0]-'0'];
    }
    int num[1000];
    for(int i=0,j=len-1;i<len;i++,j--){
        num[j]=str[i]-'0';
    }

    int res=1;
    while(len>1){
         int k=num[0];
         //%calculate n/5;
         int carry=0;
         for(int i=0;i<len;i++){
             num[i]=num[i]*2+carry;
             carry=num[i]/10;
             num[i]%=10;
         }
         num[len]=carry;
         for(int i=0;i<len;i++){
              num[i]=num[i+1];
         }
         while(num[len-1]==0)
             len--;

         int temp=(num[0]+10*num[1]);
         for(int i=0;i<4;i++){
             if(circ[i]==t2[k]){
                 res=(res*circ[(i+temp)%4])%10;
                 break;
             }
         }
    }
    res=res*t1[num[0]];
    res%=10;
    return res;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    char s[1000];
    while(EOF!=scanf("%s",s)){
        printf("%d\n",F(s));
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
