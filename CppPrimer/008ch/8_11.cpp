#include<iostream>

template<typename Any>
void Swap(Any &x,Any &y);

int main(){
    using namespace std;
    int x=5,y=10;
    cout<<"before: "<<x<<" "<<y<<endl;
    Swap(x,y);
    cout<<"after: "<<x<<" "<<y<<endl;

    {
    double x=5.5,y=10.1;
    cout<<"before: "<<x<<" "<<y<<endl;
    Swap(x,y);
    cout<<"after: "<<x<<" "<<y<<endl;
    }
    return 0;
}


template<typename Any>
void Swap(Any &x,Any &y){
    Any tmp=x;
    x=y;
    y=tmp;
}
