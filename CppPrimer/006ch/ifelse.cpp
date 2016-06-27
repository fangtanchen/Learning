#include<iostream>

int main(){
    using namespace std;
    char ch;
    cout<<"Type, and I shall repeat.\n";
    cin.get(ch);
    while(ch!='.'){
        if('\n'==ch)cout<<ch;
        else cout<<++ch;
        cin.get(ch);
    }
    cout<<"\nPlease excuse the slight confusion.\n";

}
