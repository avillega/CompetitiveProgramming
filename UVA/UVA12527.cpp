#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(string a){
    vector<bool> digits(10, false);
    int i = 0, n;
    while(i < a.size()){
        n = a[i] - '0';
        if(!digits[n]){
            digits[n]=true;;
            i++;
        }else{
            return false;
        }
    }
    return true;

}

int main(){_
    int N, M, count=0;
    while(cin >> N >> M){
        count = 0;
        while(N<=M){
            count = check(to_string(N)) ? count+1 : count;
            N++;
        }
        cout << count << '\n';
    }
    return 0;  

}