// ***************************************
// @author   :: Dip patel
// @platform :: g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
// @date     :: sep 7 23:20
// @version  :: 0.0.1
// @about    :: gujrati to gujlish..
// ***************************************

#include<bits/stdc++.h>
using namespace std;
string solve(const map<int,string> &buffer,const wstring &temp);
int main()
{
    locale::global(locale(""));
    fstream fio("number_to_letter.txt",ios::in);
    map<int,string> buffer;
    string num_str,str;
    while(fio)
    {
        fio>>num_str>>str;
        buffer.insert(pair<int,string>(stoi(num_str,0,16),str));
    }
    wstring temp;
    wcin>>temp;
    cout<<solve(buffer,temp)<<endl;
    return 0;
}

string solve(const map<int,string> &buffer,const wstring &temp)
{
    int size=temp.length();
    string ans;
    for(int i=0;i<size;i++)
    {
        if(0x0abe<=int(temp[i]) && int(temp[i])<=0x0acc) 
            if(ans[ans.length()-1]=='A') ans.pop_back();
        if(int(temp[i])==0x0acd) ans.pop_back();
        else ans+=buffer.at(int(temp[i]));
    }   
    if(temp[size-1]!=0x0abe && ans[ans.length()-1]=='A') ans.pop_back();     
    return ans;
    
}