#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int> vis, paths;
vector<vector<int>> adj;

void dfs(int u) {
    if(vis[u]) return;
    vis[u]=1;

    for(int v : adj[u])
        dfs(v);

}

signed main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    vis.resize(n);
    adj.resize(n);

    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; ++i) {
        if(!vis[i]) paths.push_back(i), dfs(i); 
    }

    cout << paths.size()-1 << '\n';
    for(int i=1; i<paths.size(); ++i) cout << paths[i-1]+1 << ' ' << paths[i]+1 << '\n';
}