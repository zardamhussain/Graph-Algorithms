#include<bits/stdc++.h>
using namespace std;

int n, m, found = 0;

vector<int> vis, path;
vector<vector<int>> adj;


void print_path(int u) {
    found = true;
    int sz = 1;
    string ans = to_string(u+1) + " ";

    for(int x : path | views::reverse) {
        ans += to_string(x+1) + " ";
        sz++;
        if(x == u)break;
    }

    cout << sz << '\n';
    cout << ans << '\n';
}


void dfs(int u, int p) {
    if(found) return;
    if(vis[u]) {
        if(vis[u] == 1) {
            print_path(u);
            return;
        }
    }

    vis[u] = 1;
    path.push_back(u);
    for(int v : adj[u]) {
        if(p != v) 
            dfs(v, u);
    }
    path.pop_back();
    vis[u] = 2;
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
        if(!vis[i]) {
            dfs(i, -1);
            if(found) break;
        }
    }

    if(!found)
     cout << "IMPOSSIBLE";
}