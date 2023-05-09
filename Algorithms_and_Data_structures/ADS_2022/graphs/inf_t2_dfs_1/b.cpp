#include <bits/stdc++.h>

using namespace std;


vector<int> g[100000];
int used[100000];

vector<vector<int>> res;
vector<int> a;

void dfs(int v) {
    a.push_back(v);
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (used[y] == 0){
            dfs(y);
        }
    }
}


int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i);
            res.push_back(a);
            a.clear();
        }
    }
    
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].size() << "\n";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}