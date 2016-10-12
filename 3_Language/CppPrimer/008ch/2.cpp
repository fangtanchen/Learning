#include<iostream>

template<typename Any>
void Swap(Any &x, Any &y);

template<typename Any>
void Swap(Any *x, Any *y, int n);

template<typename Any>
void Show(Any *x);

const int Lim=8;


int main(){
    using namespace std;
    int i=10,j=20;
    cout<<"i:"<<i<<" ,j:"<<j<<endl;
    Swap(i,j);
    cout<<"i:"<<i<<" ,j:"<<j<<endl;

    int d1[]={0,7,0,4,1,7,7,6};
    int d2[]={0,6,2,0,1,9,6,9};
    Show(d1);
    Show(d2);
    Swap(d1,d2,Lim);
    Show(d1);
    Show(d2);
    return 0;
}

template<typename Any>
void Swap(Any &x, Any &y){
     Any tmp=x;
     x=y;
     y=tmp;
}


template<typename Any>
void Swap(Any *x, Any *y, int n){
    for(int i=0;i<8;i++){
        Any tmp=x[i];
        x[i]=y[i];
        y[i]=tmp;
    }
}

template<typename Any>
void Show(Any a[]){
    using namespace std;
    for(int i=0;i<Lim;i++){
        cout<< a[i]<<" ";
    }
    cout<<endl;
}

