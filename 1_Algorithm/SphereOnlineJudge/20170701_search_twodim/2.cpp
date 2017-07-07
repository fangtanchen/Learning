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

class Solution {
    public:
        bool Find(int target, vector<vector<int> > array) {
            int nr,nc;
            nr=array.size();
            if(nr==0)return false;
            nc=array[0].size();
            for(int ri=0;ri<nr;ri++){
                int l=0,r=nc-1;
                if(array[ri][l]>target||
                        array[ri][r]<target)continue;
                while(l+1<r){
                    int mid=(l+r)/2;
                    if(array[ri][mid]<=target)l=mid;
                    else r=mid;

                }
                if(array[ri][l]==target)return true;
            }
            return false;
        }
};



int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    Solution ret;
    vector<vector<int> > A;
    int kk[3][4]={
        1,2,10,15,
        3,5,11,16,
        5,7,12,17
    };
    for(int i=0;i<3;i++){
        vector<int> tmp;
        for(int j=0;j<4;j++){
            tmp.push_back(kk[i][j]);
        }
        A.push_back(tmp);
    }
    cout<<ret.Find(10,A)<<endl;;

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
