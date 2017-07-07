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
const int MAXN=1005;

class Solution {
    public:
        double Power(double base, int exponent) {
            double ret=1;
            while(exponent){
                if(1&exponent){
                    ret*=base;

                }
                base*=base;
                exponent>>=1;

            }
            return ret;
        }
};


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Solution A;
    cout<<A.Power(1,100000)<<endl;
    cout<<A.Power(2,10)<<endl;
    cout<<A.Power(3,10)<<endl;
    cout<<A.Power(3.1,10)<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
