#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){_
    
    int L,M,Z,I, count=0;
    int i = 1;
    while(true){
        
        count = 0;
        cin >> Z >> I >> M >> L;
        if(Z == 0 && I==0 && M==0 && L==0) break;
        vector<bool> a(M+1, false);
        L = (Z*L +I)%M;
        while(!a[L]){
            count++;
            a[L]=true;
            L = (Z*L +I)%M;
        }
        cout << "Case " << i++ << ": " << count << '\n';
    }
    return 0;
}