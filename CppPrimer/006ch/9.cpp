#include<iostream>
#include<fstream>
#include<cstdlib>

int main(){
    using namespace std;
    ifstream inFile;
    ofstream outFile;

    inFile.open("in.txt");
    if(!inFile.is_open()){
        cout<<"not exist"<<endl;
        exit(EXIT_FAILURE);
    }
    int n;
    inFile>>n;
    inFile.get();
    for(int i=0;i<n;i++){
        char str[1000];
        int val;
        inFile.getline(str,1000,'\n');
        inFile>>val;
        inFile.get();
        cout<<str<<"____"<<val<<endl;
    }

    inFile.close();
    return 0;
}

