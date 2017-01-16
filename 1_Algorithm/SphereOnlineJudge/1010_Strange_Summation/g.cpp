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
const long long int n=1e9;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("in.txt","w",stdout);
	#endif
        printf("1\n");
        long long int l,r;
        long long unsigned int top=1;
        top=top<<63;
        srand(time(NULL));
        do{
            l=rand()%n*n+rand()%n;
        }while(l>=top);
        do{
            r=rand()%n*n+rand()%n;
        }while(r>=top);

        //l=rand()%n;
        //r=rand()%n;
        if(l>r)swap(l,r);
        printf("%lld %lld\n",l,r);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
