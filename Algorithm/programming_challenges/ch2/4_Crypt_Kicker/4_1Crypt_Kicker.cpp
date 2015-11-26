#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<sstream>

//#define U_DEBUG
//#define L_JUDGE

using namespace std;

vector< vector<string> > dict(16);
vector< string >  words;
int num_words;
string ch2ch;

int cmpstr(string s1, string s2){
	if(s1.length()>=s2.length())
		return true;
	else
		return false;
}

bool inDict(vector< string> container, string ss){
	if(container.end()==find(container.begin(),
		container.end(),ss))
		return false;
	else 
		return true;
}

string signature(string str){
	string temp="";
	temp+=(char)(64+0);
	for(int i=1;i<str.length();i++){
		int ok=1;
		for(int j=0;j<i;j++){
			if(str[i]==str[j]){
				temp+=temp[j];
				ok=0;
				break;
			}
		}
		if(ok){
			temp+=char(64+i);
		}
	}
	return temp;
}

int caseMatch(string s1, string s2){
	if(signature(s1)==signature(s2))
		return true;
	else 
		return false;
}


int decipher(int pos){
	if(pos==num_words)
		return true;
		
	int len=words[pos].size();
	for(int i=0;i<dict[len].size();i++){
		string temp_ch2ch=ch2ch;		
		if(caseMatch(dict[len][i],words[pos])){
			int ok=true;
			for(int j=0;j<words[pos].size();j++){
				if(ch2ch[words[pos][j]-'a']=='*'){
					ch2ch[words[pos][j]-'a']=dict[len][i][j];
				}
				else{
					if(dict[len][i][j]!=ch2ch[words[pos][j]-'a']){ 
						ok=false;
						break;
					}
				}
			}
			if(ok){
				if(decipher(pos+1))
					return true;
			}
		}		
		ch2ch=temp_ch2ch;		
	}//for(int i=0;i<dict[len].size();i++)
	return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int n;
	cin>>n;
	string temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		//cout<<temp<<" "<<temp.length()<<endl;
		dict.at(temp.length()).push_back(temp);
	}
	string line;
	while(getline(cin,line)){
		if(""==line)
			continue;
		
		words.clear();
		stringstream sstr;
		sstr<<line;
		string tmp;
		while(sstr>>tmp){
			if(!inDict(words,tmp)){
				words.push_back(tmp);
			}
		}
		num_words=words.size();
		
		#ifdef U_DEBUG
			cout<<"output dict:"<<endl;
			for(int i=1;i<=15;i++){
				for(int j=0;j<dict[i].size();j++)
					cout<<dict[i][j]<<endl;
			}
			cout<<endl<<endl<<endl<<endl;
			
			cout<<"output words:"<<endl;
			cout<<line<<"  "<<sstr<<endl;
			for(int i=0;i<words.size();i++)
				cout<<words[i]<<", ";
			cout<<endl<<endl<<endl<<endl;
		#endif
		
		sort(words.begin(),words.end(),cmpstr);
		#ifdef U_DEBUG
			cout<<"test sorts"<<endl;
			for(int i=0;i<words.size();i++)
				cout<<words[i]<<", ";
			cout<<endl<<endl<<endl<<endl;
		#endif
		
		// decrypted
		ch2ch="";
		for(int i=0;i<=30;i++){
			ch2ch+="*";
		}
		decipher(0);
		
		#ifdef U_DEBUG
			cout<<"decrypt codes:"<<endl;
			cout<<ch2ch<<endl<<endl<<endl<<endl;
		#endif
		
		for(int i=0;i<line.size();i++){
			if(line[i]==' ')cout<<" ";
			else{
				cout<<ch2ch[line[i]-'a'];
			}
		}
		cout<<endl;
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif
	
	return 0;
}



