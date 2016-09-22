#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f(a, b, c) for(int a = b; a < c; a++)
#define ra(a, b) f(a, 0, b)
typedef vector< vector<bool> > supports;
typedef pair<int, int> seat;


int main(){_
    int R, C, P, G;
    
    char row, side;
    int col;

    while(cin >> R >> C){
        if(R == 0 && C==0) break;
        supports supp(R, vector<bool>(C+1, false));
        
        cin >> P;
        while(P--){
            cin >> row >> col >> side;
            if(side == '-')
                supp[row-'A'][col -1] = true;
            else
                supp[row-'A'][col] = true; 
        }
        cin >> G;
        vector<seat> vec(G);
        ra(i, G){
            cin >> row >> col;
            vec[i] = {row-'A', col-1};
        }
        sort(vec.begin(), vec.end());
        bool salida = false;
        int i = 0;
        while(i < G && !salida){
            seat s = vec[i];
            //cout << s.first << ' ' << s.second << ";";
            if(!supp[s.first][s.second])
               supp[s.first][s.second] = true;
            else if(!supp[s.first][s.second+1]){
                supp[s.first][s.second+1] = true;
            }               
            else
                salida = true;
            i++;
        }
        //cout << '\n';
        if(!salida) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
