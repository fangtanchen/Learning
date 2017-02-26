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
const int MAXN=20000005;

char s1[MAXN],s2[MAXN];
int N;

bool cmp(char x,char y){
    return x>=y;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    if(N<=0||N>1000){
         printf("0\n0\n");
         return 0;
    }
    scanf("%s",s1);
    scanf("%s",s2);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(s1[i]<s1[j]){
                swap(s1[i],s1[j]);
            }
            if(s2[i]<s2[j]){
                swap(s2[i],s2[j]);
            }
        }
    }
    int a1=0,a2=0,i,j;
    for(i=0,j=0;i<N&&j<N;){
        if(s1[i]>s2[j]){
            a1++;
            i++;
        }else{
            j++;
            i++;
        }
    }
    printf("%d\n",a1);
    a1=0;
    for(i=0,j=0;i<N&&j<N;){
        if(s2[j]>s1[i]){
             i++;
             j++;
             a1++;
        }else{
             i++;
        }
    }
    printf("%d\n",a1);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
