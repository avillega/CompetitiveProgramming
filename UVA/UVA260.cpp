#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f(i, a) for(int i = 0; i < a; i++)
typedef pair<int, int> node;

bool dfs(vector<string> board, node start, int N, vector<vector<bool>> &visited){
    
    stack<node> s;
    s.push(start);
    node top;
    while(!s.empty()){
        top = s.top();
        s.pop();
        if(top.first < 0 || top.first >= N) continue;
        if(top.second < 0 || top.second >= N) continue;
        if(visited[top.first][top.second]) continue;
        if(board[top.first][top.second]!= 'b') continue;

        visited[top.first][top.second] = true;
        if(top.first == N-1) return true;
        else{
            s.push(node(top.first -1, top.second-1));
            s.push(node(top.first, top.second-1));
            s.push(node(top.first +1, top.second));
            s.push(node(top.first -1, top.second));
            s.push(node(top.first, top.second+1));
            s.push(node(top.first +1, top.second+1));
        }

    }
    return false;
    
}

int main(){_
    int N, c=1;
    while(cin >> N){
        if(N==0) break;
        vector<vector<bool>> visited(N, vector<bool>(N));
        vector<string> board(N);
        string temp;
        f(i, N){
            cin >> board[i];            
        }
        bool salir = false;
        f(i, N){
            if(salir) break;
            if(board[0][i] != 'b') continue;
            salir = dfs(board, node(0, i), N, visited);
        }
        if(salir) cout << c << " B\n";
        else cout << c << " W\n";
        c++;

    }
    return 0;

}

