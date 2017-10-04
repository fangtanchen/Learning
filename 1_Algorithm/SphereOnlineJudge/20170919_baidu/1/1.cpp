#include<iostream>


using namespace std;

const int MAXN=1e5+10;

int a[MAXN],b[MAXN];
int alen,blen;


int main(void){
    cin.sync_with_stdio(false);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>alen;
    for(int i=0;i<=alen;i++){
        cin>>a[i];
    }
    cin>>blen;
    for(int i=0;i<=blen;i++){
        cin>>b[i];
    }
    int i;
    int status=0;//-1: < 1: > 0:==
    for(i=0;i<=alen||i<=blen;i++){
        if((i&1)==0){
            if(a[i]>b[i]){
                status=1;
                break;
            }else if(a[i]<b[i]){
                status=-1;
                break;
            }
        }
        else{
            if(a[i]<b[i]){
                status=1;
                break;
            }else if(a[i]>b[i]){
                status=-1;
                break;
            }
        }
    }
    if(0==status)cout<<"="<<endl;
    else if(1==status)cout<<">"<<endl;
    else cout<<"<"<<endl;

    return 0;
}
