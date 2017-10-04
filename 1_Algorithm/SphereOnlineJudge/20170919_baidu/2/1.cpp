#include<iostream>
#include<cstring>


using namespace std;

const int MAXN=1e6+10;
char str[MAXN];
int l[MAXN],r[MAXN];


int main(){
    cin>>str;

    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    int slen=strlen(str);
    l[0]=0;
    for(int i=1;i<=slen;i++){
        if(str[i-1]=='E'){
            l[i]=l[i-1]+1;
        }else{
            l[i]=l[i-1];
        }
    }
    for(int i=slen-1;i>=0;i--){
        r[i]=r[i+1];
        if(str[i]=='W'){
            r[i]++;
        }
    }
    int sum=0x5fffffff;
    int imax=slen-1;
    for(int i=0;i<=slen;i++){
        int tmp=l[i]+r[i];
        if(tmp<sum)sum=tmp;
    }
    cout<<sum<<endl;

    return 0;
}
