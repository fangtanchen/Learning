#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+10;

char in[MAXN];
char out[MAXN];
char tmp[MAXN];

void unzip (const char* input, char* output){
    int inlen=strlen(input);
    int outlen=0;
    int cnt=0;
    bool flag=false;
    for(int i=0;i<inlen;i++){
        if(input[i]>='a'&&input[i]<='z'){
            if(!flag){
                output[outlen++]=input[i];
            }else{
                if(cnt==0)output[outlen++]=input[i];
                else{
                    while(cnt--){
                        output[outlen++]=input[i];
                    }
                }
                flag=false;
                cnt=0;
            }
        }else{
            cnt=cnt*10+input[i]-'0';
            flag=true;
        }
    }
    output[outlen]=0;
#ifdef L_JUDGE
    cout<<output<<endl;
#endif
    char *tmp=(char*)malloc(strlen(output));
    int tmplen=0;
    for(int i=0;i<outlen;){
         int j=i+1;
         while(output[j]==output[i])j++;
         if(j-i==1){
             tmp[tmplen++]=output[i];
         }else if(j-i==2){
             tmp[tmplen++]=output[i];
             tmp[tmplen++]=output[i];
         }else{
             char str[100];
             int cnt=j-i;
             int slen=0;
             while(cnt){
                  str[slen++]=cnt%10+'0';
                  cnt/=10;
             }
             for(int j=slen-1;j>=0;j--){
                 tmp[tmplen++]=str[j];
             }
             tmp[tmplen++]=output[i];
         }
         i=j;
    }
    if(tmplen!=inlen){
        strcpy(output,"!error");
    }
    for(int i=0;i<tmplen;i++){
        if(tmp[i]!=input[i]){
            strcpy(output,"!error");
            break;
        }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>in;
    unzip(in,out);
    cout<<out<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
