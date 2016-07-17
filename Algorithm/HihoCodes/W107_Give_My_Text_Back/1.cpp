#include<iostream>
#include<vector>
#include<string>
#include<cstdio>


#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

vector<string> input;
string word="";
char c;
string pun;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        word="";
        while(cin>>noskipws>>c){
            if(isalpha(c)){
                if(c>='A'&&(c<='Z')){
                    c+=32;
                }
                word+=c;
            }else{
                if(word!=""){
                    input.push_back(word);
                    word="";
                }
                if(c!=' '){
                    pun=c;
                    input.push_back(pun);
                }
            }
        }
    bool firstWord=true;
    int imax=input.size();
    for(int i=0;i<imax;i++){
        if(input[i]==","){
            cout<<',';
        }else if(input[i]=="."){
            cout<<'.';
            firstWord=true;
            }else if(input[i]=="\n"){
             cout<<endl;
             }else{
                if(i>0 && input[i-1]!="\n")
                    cout<<" ";
                    if(firstWord){
                        input[i][0]-=32;
                        firstWord=false;
                    }
                    cout<<input[i];

             }

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
