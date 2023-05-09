#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000000];
bool used[1000000];

void dfs(int v) {
    used[v] = true;
    for (auto y: g[v]) {
        if (used[y] == false) {
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
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int c1, c2;
    cin >> c1 >> c2;
    c1--;
    c2--;

    dfs(c1);

    if (used[c2]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}