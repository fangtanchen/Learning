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
                if(array[ri][ri]<target){
                    continue;

                }
                if(array[ri][ri]==target
                        ||array[ri][0]==target
                        ||array[0][ri]==target)return true;

                if(array[ri][0]<target){
                    int l=0,r=ri;
                    while(l+1<r){
                        int mid=(l+r)/2;
                        if(array[ri][mid]<target)l=mid;
                        else if(array[ri][mid]==target)return true;
                        else r=mid;

                    }

                }
                if(array[0][ri]<target){
                    int l=0,r=ri;
                    while(l+1<r){
                        int mid=(l+r)/2;
                        if(array[mid][ri]<target)l=mid;
                        else if(array[mid][ri]==target)return true;
                        else r=mid;

                    }

                }

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
    int kk[3][3]={
        1,2,10,
        3,5,11,
        5,7,12
    };
    cout<<ret.Find(10,A)<<endl;;

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
