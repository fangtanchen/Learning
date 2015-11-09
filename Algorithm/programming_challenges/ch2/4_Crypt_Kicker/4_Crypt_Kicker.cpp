/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

#define U_DEBUG
#define ONLINE_JUDGE

vector< vector< string > > dict(16);
vector< string> words;
string cipher="";
string trys="";
int wordLen;

//debug input



bool inContainer(vector<string> &s, string aa){
	if(find(s.begin(),s.end(),aa)==s.end())
		return false;
	return true;
}


string giveSignature(string &a){
	string na="A";
	for(int i=1;i<a.size();i++){
		bool ok=false;
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
				na+=char(64+j);
				ok=true;
				break;
			}
		}
		if(!ok)
			na+=char(64+i);
	}
	return na;
}

bool caseMatch(string &a, string &b){
	if(a.length()==1)
		return true;
		
	if(giveSignature(a)==giveSignature(b))
		return true;
	
	return false;
}

bool cmpstr(string a, string b){
	return a.length()>b.length();
}

bool decipher(int pos){
	if(pos==wordLen)
		return true;
		
	string cipherTmp=cipher;
	string tryTmp=trys;
	int len=words[pos].length()-1;
	for(int i=0;i<dict[len].size();i++){
		bool ok=true;
		if(caseMatch(dict[len][i],words[pos])){
			for(int j=0;j<=words[pos].length()-1;j++){
				int idx=words[pos][j]-'a';
				if(cipher[idx]=='*'){
					if('0'==trys[dict[len][i][j]-'a']){
						cipher[idx]=dict[len][i][j];
						trys[dict[len][i][j]-'a']='1';
					}
				}
				else{
					if(cipher[idx]!=dict[len][i][j]){
						ok=false;
					}
				}
			}
			if(ok){
				if(decipher(pos+1))
					return true;
			}
		}
		cipher=cipherTmp;
		trys=tryTmp;
	}
	return false;
}



int main(){

#ifdef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		dict.at(temp.length()-1).push_back(temp);
	}
	
	string line;
	cin.get();
	while(getline(cin,line)){
		if(line=="")
			continue;
			
		words.clear();
		cipher="";
		trys="";
		stringstream tostring;
		tostring<<line;
		string tmp;
		while(tostring>>tmp){
			if(!inContainer(words,tmp))
				words.push_back(tmp);
		}
		wordLen=words.size();
		sort(words.begin(),words.end(),cmpstr);
		
		for(int i=0;i<26;i++){
			cipher+='*';
			trys+='0';
		}
		decipher(0);
		for(int i=0;i<line.length();i++){
			if(line[i]!=' ')
				cout<<cipher[line[i]-'a'];
			else 
				cout<<' ';
		}
		cout<<endl;
	}
	
	#ifdef U_DEBUG
		
	#endif
	
	
		
#ifdef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}




*/
