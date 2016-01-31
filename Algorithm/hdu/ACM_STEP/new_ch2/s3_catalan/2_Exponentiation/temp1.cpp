#include <math.h>
#include <iostream>
#include <string>
#include<cstdio>
using namespace std;


//#define U_DEBUG
#define L_JUDGE

string AddString(string a, string b)
{
    int len = a.length()>b.length() ? a.length() : b.length();
    if(len == a.length()){
        string auxi(len - b.length(), '0');
        b = auxi + b;
    }
    else{
        string auxi(len- a.length(), '0');
        a = auxi + a;
    }
    int i;
    string result = a;
    int sum = 0;
    int carry = 0;
    for(i=len-1; i>=0; --i){
        sum = a.at(i) + b.at(i) - '0' - '0' + carry;
        carry = sum / 10;
        result[i] = sum % 10 + '0';
    }
    if (carry != 0){
        result = (char)(carry + '0') + result;
    }
    return result;
}

string multiply(const string &a, const string &b)
{
    if(a.length() < 4 && b.length() < 4){//可以直接相乘，这里作为递归的终止条件

        long aInt = atof(a.c_str());
        long bInt = atof(b.c_str());
        char buffer[100];
        sprintf(buffer, "%d", aInt*bInt);
        string result(buffer);
        return result;
    }
    int aLen = a.length();
    int bLen = b.length();
    int aHalfLen = a.length() / 2;
    int bHalfLen = b.length() / 2;
    string str1_1 = a.substr(0, aHalfLen);
    string str1_2 = a.substr(aHalfLen, aLen - aHalfLen);
    string str2_1 = b.substr(0, bHalfLen);
    string str2_2 = b.substr(bHalfLen, bLen-bHalfLen);

    string str11 = multiply(str1_1, str2_1);
    string str12 = multiply(str1_1, str2_2);
    string str21 = multiply(str1_2, str2_1);
    string str22 = multiply(str1_2, str2_2);
    str12.append(aLen-aHalfLen, '0');
    str21.append(bLen-bHalfLen, '0');
    str11.append(aLen+bLen-aHalfLen-bHalfLen, '0');
    string result = AddString(str11, str12);
    result = AddString(result ,str21);
    result = AddString(result ,str22);
    return result;
}

int main()
{ 
    #ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
	#endif
    int expo = 0;
    char buff[100];
    while(scanf("%s%d", buff, &expo) != EOF)
    {
        string str(buff);
        int start = 0;
        while(true){//越过开始的0

            if(start <= str.length()-1 && str.at(start) == '0'){
                ++start;
            }
            else{
                break;
            }
        }
        int end = str.length()-1;
        while(true){//越过结束的0

            if(end >= 0 && str.at(end) == '0'){
                --end;
            }
            else{
                break;
            }
        }
        if(start > end){
            cout<<"0"<<endl;
            continue;
        }
        str = str.substr(start, end - start + 1);
        int pos = str.find('.');
        int dot = str.length() - 1 - pos;
        if(pos != -1){//删除小数点

            str = str.erase(pos, 1);
        }

        int time = expo;
        string str2 = str;
        string str1 = str;
        string result = "1";
        if (time%2 != 0){
            result = str;
        }
        time /= 2;
        while(time){
            str2 = multiply(str1, str1); 
            if (time%2 != 0){
                result = multiply(result, str2);
            }
            time /= 2;
            str1 = str2;
        }
        str2 = result;
        if( pos == -1 )
        {
        }
        else{
            dot *= expo;
            if(dot > str2.length()){
                string auxi(dot - str2.length(), '0');
                str2 = '.' + auxi + str2;
            }
            else{
                str2.insert(str2.length() - dot, ".");
            }
        }
        if(str2.at( str2.length()-1 ) == '.'){
            str2.erase(str2.length()-1, 1);
        }
        cout<<str2<<endl;
    }
    
    #ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out2.txt");
	#endif
	
    return 0;
}
