#include <iostream>
#include <vector>

using namespace std;
int n, m, x, y, v;

int used[100];
vector<int> g[100];

void dfs(int v) { // v - y
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (used[y] == 0)
            dfs(y);
    }
    
}

int main() {
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (used[i] == 0) {
            cnt += 1;
            dfs(i);
        }
    cout << cnt;
    return 0;
}