#include <bits/stdc++.h> 
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f(i, a) for(int i = 0; i < a ; i++)
typedef vector<vector<int>> vvi;
 

int bfs(vvi graph, vector<bool> &vis, queue<int> &q){
    int count=0;   
    int front;
    while(!q.empty()){
        front = q.front();        
        q.pop();
        if(vis[front]) continue;
        vis[front] = true;
        count++;
        for(int i = 0; i < graph[front].size(); i++){
            if(!vis[graph[front][i]])
                q.push(graph[front][i]);
        }
    }
    return count;
}

int main(){_
    int T, n, m, l, count; 
    cin >> T;
    while(T--){
        count = 0;
        cin >> n >> m >> l;
        vector<bool> visited(n+1, false);
        vector<vector<int>> graph(n+1);
        queue<int> dropHand;
        int a, b;
        while(m--){
            cin >> a >> b;
            if(a != b)
                graph[a].push_back(b);
        }
        int tmp;
        f(i, l){
            cin >> tmp;
            dropHand.push(tmp);
        }
        count = bfs(graph, visited, dropHand);
        cout << count << '\n';      

    }
    return 0;
}
