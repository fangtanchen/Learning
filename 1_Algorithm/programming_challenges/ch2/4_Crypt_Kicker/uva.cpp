#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;

map<string, int> exist;
char words[1100][200],lines[1000];

vector<string> text;

string word;

bool mapto[800][1100];

int ans[27],cnt[800],rans[27],n;
bool visited[800];

int dt[26][26];

bool check_map(int a,int b)
{
    if(ans[a]==b&&rans[b]==a)
        return true;
    if(ans[a]==-1&&rans[b]==-1)
        return true;
    return false;
}
/*
void check()
{
     int i,j,k;
     bool flag;
     for(i=0;i<text.size();i++)
     {
         for(j=0;j<n;j++)
         {
             if(mapto[i][j])
             {
                 flag=true;
                 for(k=0;text[i][k];k++)
                 {
                     flag=check_map(words[j][k]-'a',text[i][k]-'a');
                     if(flag==false)
                        break;
                 }
                 if(flag==false)
                 {
                     mapto[i][j]=false;
                     cnt[i]--;
                 }
             }
         }
         
     }
}
*/


bool gao(int level)
{
     //cout<<level<<endl;
     if(level==text.size())
         return true;
     int i,ct=1000,cid,j,k;
     for(i=0;i<text.size();i++)
     {
         if(visited[i]==false&&cnt[i]<ct)
         {
             ct=cnt[i];
             cid=i;
         }
     }
     if(ct==0)
         return false;
     visited[cid]=true;
     for(i=0;i<n;i++)
     {
         if(mapto[cid][i])
         {
             bool flag=true;
             for(j=0;text[cid][j];j++)
             {
                 dt[words[i][j]-'a'][text[cid][j]-'a']++;
                 flag=flag&check_map(words[i][j]-'a',text[cid][j]-'a');
                 ans[words[i][j]-'a']=text[cid][j]-'a';
                 rans[text[cid][j]-'a']=words[i][j]-'a';
             }
             //cout<<level<<" "<<words[i]<<" "<<text[cid]<<" "<<flag<<endl;
             if(flag)
             {
                /* check();*/
                // cout<<"yes"<<endl;
                 if(gao(level+1))
                     return true;
                 recover();
             }
             for(j=0;text[cid][j];j++)
                 dt[words[i][j]-'a'][text[cid][j]-'a']--;
             memset(ans,-1,sizeof(ans));
             memset(rans,-1,sizeof(rans));
             for(j=0;j<26;j++)
                 for(k=0;k<26;k++)
                     if(dt[j][k]!=0)
                     {
                         ans[j]=k;
                         rans[k]=j;
                     }
                         
         }
     }
     visited[cid]=false;
     return false;
}

int main()
{
    int i,j,k,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",words[i]);
    getchar();
    while(gets(lines))
    {
        memset(mapto,false,sizeof(mapto));
        memset(ans,-1,sizeof(ans));
        memset(rans,-1,sizeof(rans));
        memset(cnt,0,sizeof(cnt));
        memset(visited, false, sizeof(visited));
        memset(dt,0,sizeof(dt));
        text.clear();
        exist.clear();
        stringstream ss(lines);
        while(ss>>word)
        {
           if(exist[word]==0)
           {
               text.push_back(word);
               exist[word]=1;
           }
        }
        for(i=0;i<text.size();i++)
        {
            for(j=0;j<n;j++)
            {
                if(text[i].length()!=strlen(words[j]))
                    continue;
                mapto[i][j]=true;
                cnt[i]++;
            }
        }
        if(gao(0))
        {
            for(i=0;lines[i];i++)
            {
                if(lines[i]>='a'&&lines[i]<='z')
                    printf("%c",rans[lines[i]-'a']+'a');
                else
                    printf("%c",lines[i]);
            }
            puts("");
        }
        else
        {
            for(i=0;lines[i];i++)
            {
                if(lines[i]>='a'&&lines[i]<='z')
                    printf("*");
                else
                    printf("%c",lines[i]);
            }
            puts("");
        }
    }    
    return 0;
}
