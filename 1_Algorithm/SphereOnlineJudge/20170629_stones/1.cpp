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
        int ans[2];

        void Solve(long long int energyA,long long int energyB,
                int scoreA,int scoreB,int first,int stonei,
                vector<int> e,vector<int> a){
            if(stonei==e.size()){
                if(scoreA>ans[0]){
                    ans[0]=scoreA;
                    ans[1]=scoreB;
                }
                return;
            }
            if(first==0){
                if(energyA>energyB){
                    Solve(energyA+e[stonei],energyB,scoreA+a[stonei],scoreB,
                            1-first,stonei+1,e,a);
                    Solve(energyA-energyB-1,0+e[stonei],scoreA,scoreB+a[stonei],
                            first,stonei+1,e,a);
                }else{
                    Solve(0+e[stonei],energyB-energyA,scoreA+a[stonei],scoreB,
                            1-first,stonei+1,e,a);
                }
            }else{
                if(energyB>energyA){
                    Solve(energyA,energyB+e[stonei],scoreA,scoreB+a[stonei],
                            1-first,stonei+1,e,a);
                    Solve(0+e[stonei],energyB-energyA-1,scoreA+a[stonei],scoreB,
                            first,stonei+1,e,a);
                }else{
                    Solve(energyA-energyB,0+e[stonei],scoreA,scoreB+a[stonei],
                            1-first,stonei+1,e,a);
                }
            }
        }

        vector<int> result(int A, int B, int n, vector<int> e, vector<int> a) {
            // write code here
            long long int energy[2]={A,B};
            int score[2]={0,0};
            ans[0]=ans[1]=0;
            Solve(A,B,0,0,0,0,e, a);
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
