#include <bits/stdc++.h>

using namespace std;

vector<int> g[1001];
int mark[1001];

bool check = false;

void dfs(int v){
    mark[v] = 1;
    for(int u: g[v]){
        if(mark[u] == 0){
            dfs(u);
        }
         if (mark[u] == 1) {
            check = true;
            return;
        }
    }
    mark[v] = 2;
}

int main() {    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << i << "---" << mark[i] << "\n";
    }
    if (check) cout << "YES"; else cout << "NO";
    return 0;
}