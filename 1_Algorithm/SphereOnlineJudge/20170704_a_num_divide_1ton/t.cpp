#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        void reOrderArray(vector<int> &array) {
            int i,j;
            for(j=0;j<array.size()&&(array[j]&1);j++)
                ;
            for(i=j+1;i<array.size();i++)
                if(array[i]&1){
                    for(int k=i;k>j;k--){
                        swap(array[k],array[k-1]);

                    }
                    j++;
                }
        }
};


int main(){
     Solution st;
     vector<int> A;
     A.push_back(10);
     A.push_back(20);
     A.push_back(21);
     A.push_back(23);
     A.push_back(20);
     A.push_back(20);
     A.push_back(21);
     A.push_back(23);
     st.reOrderArray(A);
     for(int i=0;i<8;i++){
          cout<<A[i]<<" ";
     }
}
