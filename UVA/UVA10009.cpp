#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef map<string, vector<string> > msvs;

map<string, string> BFS(string &from, string &destiny, msvs &graph ){
    queue<string> cola;
    string actual;
    vector<string> adj;
    map<string, string> parents;
    map<string, bool> visited;
    cola.push(from);
    parents[from] = "NONE";
    while(!cola.empty()){
        actual = cola.front();
        cola.pop();
        visited[actual] = true;
        
        adj = graph[actual];
        for(string s : adj){
            if(!visited[s]){
                
                parents[s] = actual;
                if(s == destiny) return parents;
                cola.push(s);
            }
        }

    }

}

int main(){_
    int T, N,Q;
    cin >> T;
    msvs graph;
    string from, destiny;
    while(T--){
        cin >> N >> Q;
        graph.clear();
        while(N--){
            cin >> from >> destiny;
            graph[from].push_back(destiny);
            graph[destiny].push_back(from);
        }
        while(Q--){
            cin >> from >> destiny;
            map<string, string> parents = BFS(from, destiny, graph);
            string result="";
            string parent = parents[destiny];
            while(parent != "NONE"){
                result = parent[0] + result;
                parent = parents[parent];
            }
            result += destiny[0];
            cout << result << '\n';
            
        }
        if(T > 0)
            cout << '\n';
    }
    return 0;

}