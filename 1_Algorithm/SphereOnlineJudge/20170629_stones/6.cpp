#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
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
        map<pair<LL,LL>,LL> dp;

        LL Solve(int stonei,LL energy,
                vector<int> e,vector<int> a){
            if(1+stonei==a.size()){
                return a[stonei];
            }
            if(energy>0){
                //fetch the stone
                LL en=energy+e[stonei];
                LL tmp1,p1,tmp2,p2;
                en*=-1;
                if(dp.end()==dp.find(make_pair(stonei+1,en))){
                    tmp1=Solve(stonei+1,en,e,a);
                    dp.insert(make_pair(make_pair(stonei+1,en),tmp1));
                }else{
                    tmp1=dp.find(make_pair(stonei+1,en))->second;
                }
                p1=sum[stonei]-tmp1;
                //not fetch the stone
                en=energy-e[stonei];
                if(dp.end()==dp.find(make_pair(stonei+1,en))){
                    tmp2=Solve(stonei+1,en,e,a);
                    dp.insert(make_pair(make_pair(stonei+1,en),tmp1));
                }else{
                    tmp2=(dp.find(make_pair(stonei+1,en))->second);
                }
                p2=tmp2;
                return max(p1,p2);
            }else{
                //fetch the stone
                LL tmp1,p1,tmp2,p2;
                LL en=energy+e[stonei];
                en*=-1;
                if(dp.end()==dp.find(make_pair(stonei+1,en))){
                    tmp1=Solve(stonei+1,en,e,a);
                    dp.insert(make_pair(make_pair(stonei+1,en),tmp1));
                }else{
                    tmp1=(dp.find(make_pair(stonei+1,en))->second);
                }
                p1=sum[stonei]-tmp1;
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
            return ret;

        }

};


int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    int A,B,N;
    vector<int> e,a;
    cin>>A>>B>>N;
    int kk[110],tt[110];
    for(int i=0;i<N;i++){
        cin>>kk[i];
    }
    for(int i=0;i<N;i++){
        cin>>tt[i];
    }
    for(int i=0;i<N;i++)
        e.push_back(kk[i]),a.push_back(tt[i]);
    Stones st;
    vector<int> ret=st.result(A,B,N,e,a);
    cout<<ret[0]<<" "<<ret[1]<<endl;


#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
