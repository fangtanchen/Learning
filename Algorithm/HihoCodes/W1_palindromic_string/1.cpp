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

char str[1000002+1200];

int fast(char *p){
    int ans=1;
    for(int i=1;p[i];i++){
        int s=i,e=i,t;
        while(p[e+1]==p[i])++e;
        i=e;
        while(p[s-1]==p[e+1])--s,++e;
        if((t=e-s+1)>ans)ans=t;
    }
    return ans;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    str[0]='$';
    int n;
    scanf("%d",&n);
    while(n--){
         scanf("%s",str+1);
         printf("%d\n",fast(str));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
