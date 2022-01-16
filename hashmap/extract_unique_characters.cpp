#include<bits/stdc++.h>
using namespace std;

string uniqueChar(string str) {
    string s="";
	unordered_map<char,int>mp;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(mp.count(ch)>0);
        else{
            mp[ch]++;
            s+=ch;
        }
    }
    return s;
}
int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}