#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int> color;
vector<vector<int>> adj;


bool bfs(int i) {
    queue<int> q {{ i }};
    color[i]=1;
    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v : adj[u])  
            if(!color[v]) q.push(v), color[v] = color[u]==1 ? 2 : 1;
            else if(color[v] == color[u]) return 0;
    }

    return 1;
}


signed main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;

    color.resize(n);
    adj.resize(n);

    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    for(int i=0; i<n; ++i) {
        if(!color[i]) {
            if(!bfs(i)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    
    for(int x : color) cout << x << ' ';
    

}