#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){_
    int T, n, res;
    cin >> T;
    while(T--){
        cin >> n;
        res = n*(n*n*n - 6*n*n + 23*n - 18);
        res/=24;
        res+=1;
        cout << res << '\n';        
    }
    return 0;
}