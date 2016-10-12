#include<iostream>

using namespace std;

template<typename T>
T max5(const T x[]);

int main(){


    int f[5]={1,5,-5,32,55};
    cout<<max5(f)<<endl;
    double d[5]={1.1,0.1,0.01,3,5432};
    cout<<max5(d)<<endl;
    return 0;
}

template<typename T>
T max5(const T x[]){
    T t=x[0];
    for(int i=1;i<5;i++)
    {
         t=max(t,x[i]);
    }
    return t;
}
