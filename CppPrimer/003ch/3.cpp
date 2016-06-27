#include<iostream>

using namespace std;
const int T=60;
const int T2=3600;

int main(){
    double degrees,minutes,seconds;
    cout<<"Enter a latitude in degress,minutes,seconds:"<<endl;
    cout<<"First, enter the degrees: __\b\b";
    cin>>degrees;
    cout<<"Next, enter the minutes: ";
    cin>>minutes;
    cout<<"Last, enter seconds: ";
    cin>>seconds;
    double ret=degrees+minutes/T+seconds/T2;
    cout<<ret<<endl;
    return 0;
}

