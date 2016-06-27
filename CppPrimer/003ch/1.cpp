#include<iostream>

using namespace std;

int main(){
    const int ML=11;
    cout<<"input your height:___\b\b\b";
    int hei;
    cin>>hei;
    int x=hei/ML;
    int y=hei%ML;
    cout<<"transfer to:"<<x<<"chi"<<y<<"cun"<<endl;
    return 0;
}
