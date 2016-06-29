#include<iostream>

double betsy(int);
double pam(int);

void estimate(int lines,double (*pf)(int));

int main(){
    using namespace std;
    int code;
    cout<<"how many lines of code do you need? "<<endl;
    cin>>code;
    cout<<"Here's Betsy estimate:\n";
    estimate(code,betsy);
    cout<<"Here's Pam estimate:\n";
    estimate(code,pam);
    return 0;
}

double betsy(int lns){
     return 0.05*lns;
}

double pam(int lns){
    return 0.03*lns+0.0004*lns*lns;
}

void estimate(int lines, double (*pf)(int x)){
     using namespace std;
     cout <<lines<<" lines will take ";
     cout<<(*pf)(lines)<<" hours "<<endl;
}
