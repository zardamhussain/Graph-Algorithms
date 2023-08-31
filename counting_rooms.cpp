#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<string> G;

int dir[5] = { -1, 0, 1, 0, -1 };

void dfs(int i, int j) {
    if(min(i, j) < 0 || i==n || j==m || G[i][j] == '#') return;
    G[i][j] = '#';

    for(int k=0; k<4; ++k)
        dfs(i+dir[k], j+dir[k+1]);

}   

signed main() {
    cin >> n >> m;
    G.resize(n);
    for(int i=0; i<n; ++i) 
        cin >> G[i];

    int count = 0;   
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(G[i][j] == '.') count++, dfs(i, j);
        } 
    }

    cout << count;
}