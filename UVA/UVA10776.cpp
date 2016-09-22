#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(), v.end()

void nextSeq(string &chars, int n, string s, int start){
    if(s.length()==n){
        cout << s << '\n';
    }else{
        for(int i = start; i < chars.length();){
            nextSeq(chars, n, s + chars[i], i+1);
            char c = chars[i];
            i++;
            while(chars[i]==c) i++;
        }
    }
}

int main(){
    string chars;
    int n;
    while(cin >> chars >> n){
        sort(all(chars));
        nextSeq(chars, n, "", 0);
    }
}