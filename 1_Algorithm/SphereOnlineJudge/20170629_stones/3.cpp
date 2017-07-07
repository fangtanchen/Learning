#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;


class Stones {
    public:
        typedef long long int LL;
        int ans[2];
        LL sum[110];

        LL Solve(int stonei,LL energy,
                vector<int> e,vector<int> a){
            if(1+stonei==a.size()){
                return a[stonei];
            }
            if(energy>0){
                //first hand, fetch the stone
                LL en=energy+e[stonei];
                en*=-1;
                LL tmp1=Solve(stonei+1,en,e,a);
                LL p1=sum[stonei]-tmp1+a[stonei];
                //first hand, not fetch the stone
                en=energy-e[stonei];
                LL tmp2=Solve(stonei+1,en,e,a);
                LL p2=tmp2;
                return max(p1,p2);
            }else{
                //fetch the stone
                LL en=energy+e[stonei];
                en*=-1;
                LL tmp1=Solve(stonei+1,en,e,a);
                LL p1=sum[stonei]-tmp1+a[stonei];
                return p1;
            }
        }

        vector<int> result(int A, int B, int n, vector<int> e, vector<int> a) {
            // write code here
            ans[0]=ans[1]=0;
            sum[a.size()]=0;
            for(int i=a.size()-1;i>=0;i--)
                sum[i]=sum[i+1]+a[i];
            ans[0]=Solve(0,A-B,e, a);
            ans[1]=sum[0]-ans[0];
            vector<int> ret;
            ret.push_back(ans[0]);
            ret.push_back(ans[1]);
            cout<<ans[0]<<" "<<ans[1]<<endl;
            return ret;

        }

};


int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    vector<int> e,a;
    int kk[]={66,2,6,2,8,4,3};
    int tt[]={7,12,65,7,4,40,15};
    for(int i=0;i<7;i++)
        e.push_back(kk[i]),a.push_back(tt[i]);
    Stones st;
    st.result(9,0,7,e,a);


#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
