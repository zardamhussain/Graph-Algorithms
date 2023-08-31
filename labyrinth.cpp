#include<bits/stdc++.h>
using namespace std;

int n, m, si, sj, ei, ej;

vector<string> G;
            //   U  R  D   L 
int dir[5] = { -1, 0, 1, 0, -1 };
string dir2 = "URDL";
int last[1001][1001];

int bfs(int i, int j) {
    queue<int> q;

    q.emplace(i*m+j);

    int count = 0;

    while(!q.empty()) {
        
        for(int i=q.size(); i>0; --i) {
            auto x = q.front(); q.pop();
            int r = x/m, c = x%m;
            if(r == ei && c == ej) return count;
            for(int k=0; k<4; ++k) {
                int a = r + dir[k], b = c + dir[k+1];
                if(min(a, b) < 0 || a == n || b == m || G[a][b] == '#') continue;
                G[a][b] = '#';
                q.push(a*m+b);
                last[a][b] = k;
            }
        }
        
        count++;
    }


    return -1;

}  

signed main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    G.resize(n);
    for(int i=0; i<n; ++i) 
        cin >> G[i];


    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(G[i][j] == 'A') si = i, sj=j;
            if(G[i][j] == 'B') ei = i, ej=j;
        } 
    }

    auto a = bfs(si, sj);
    
    if(a != -1) {
        cout << "YES\n";
        cout << a << '\n';
        string ans;

        while(!(ei == si && ej == sj)) {
            int l = last[ei][ej];
            ans.push_back(dir2[l]);
            ei = ei - dir[l];           
            ej = ej - dir[l+1];           
        }      

        for(char x : ans | views::reverse) cout << x; 
 
    }else cout <<"NO\n";
}