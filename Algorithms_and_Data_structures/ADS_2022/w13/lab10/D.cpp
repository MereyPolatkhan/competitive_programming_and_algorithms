#include <bits/stdc++.h>

using namespace std;

vector<int> g[5007];
vector<int> d(5007, INT_MAX);

void bfs(int v) {
    d[v] = 0;
    queue<int> q;
    q.push(v);

    while (q.empty() == false) {
        int cur = q.front();
        q.pop();
        for (auto y: g[cur]) {
            if (d[y] > d[cur] + 1) {
                q.push(y);
                d[y] = d[cur] + 1;
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    while (q--) {
        int cmd, v;
        cin >> cmd >> v;

        if (cmd == 1) {
            bfs(v);
        }
        else {
            if (d[v] == INT_MAX) cout << -1 << "\n";
            else cout << d[v] << "\n";
        }
    }

    return 0;
}