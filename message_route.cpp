#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int> p;
vector<vector<int>> adj;


bool bfs() {
    queue<int> q {{ 0 }};

    vector<bool> vis(n);
    vis[0]=1;
    p[0]=-1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == n-1) return 1;
        for(int v : adj[u])  
            if(!vis[v]) q.push(v), vis[v]=1, p[v]=u;
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;

    p.resize(n);
    adj.resize(n);

    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(bfs()) {
        vector<int> path;
        for(int v=n-1; v!=-1; v=p[v]) path.push_back(v+1);
        cout << path.size() << '\n';
        for(int x : path | views::reverse) cout << x <<' ';
    }
    else cout << "IMPOSSIBLE";


}