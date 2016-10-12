#include<iostream>
#include<cctype>

using namespace std;

int main(void){
    char ch;
//    ch=cin.get();
    while((ch=cin.get())!='@'){
        if(isdigit(ch))continue;
        if(islower(ch))ch=toupper(ch);
        else if(isupper(ch))ch=tolower(ch);
        cout<<ch;
    }
}
