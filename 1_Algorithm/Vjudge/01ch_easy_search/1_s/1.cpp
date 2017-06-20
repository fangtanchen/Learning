#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        bool Find(int target, vector<vector<int> > array) {
            int nr,nc;
            nr=array.size();
            nc=array[0].size();
            if(array[nr-1][nc-1]<target)return false;

            for(int ri=0;ri<min(2,nr);ri++){
                for(int ci=0;ci<min(2,nc);ci++){
                    if(array[ri][ci]==target)return true;

                }

            }
            for(int ri=2,ci=2;(ri<nr)&&(ci<nc);ri++,ci++){
                int al,ar;
                al=0;ar=ci;
                int mid;
                if(array[ri][0]==target
                        ||array[ri][ci]==target
                        ||array[0][ci]==target)return true;
                if(array[ri][0]<target&&array[ri][ci]>target){
                    while(al+1<ar){
                        mid=(al+ar)/2;
                        if(array[ri][mid]==target)return true;
                        else if(array[ri][mid]<target){
                            al=mid;

                        }else{
                            ar=mid;

                        }

                    }

                }
                al=0;ar=ri;
                if(array[0][ci]<target&&array[ri][ci]>target){
                    while(al+1<ar){
                        mid=(al+ar)/2;
                        if(array[mid][ci]==target)return true;
                        else if(array[mid][ci]<target){
                            al=mid;

                        }else{
                            ar=mid;

                        }

                    }

                }
            }

            return false;
        }
};

int main(){
    vector<vector<int> > G;
    int nr=4,nc=4;
    int A[5][5]={{1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}};
    vector<int> tmp;
    for(int i=0;i<nr;i++){
        tmp.clear();
        for(int j=0;j<nc;j++){
            tmp.push_back(A[i][j]);
        }
        G.push_back(tmp);
    }
    Solution KK;
    if(KK.Find(15,G))cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    G.clear();
    int B[5][5]={
        {1,2,8,9},
        {4,7,10,13}
    };
    for(int i=0;i<nr;i++){
        tmp.clear();
        for(int j=0;j<nc;j++){
            tmp.push_back(A[i][j]);
        }
        G.push_back(tmp);
    }
    if(KK.Find(7,G))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
