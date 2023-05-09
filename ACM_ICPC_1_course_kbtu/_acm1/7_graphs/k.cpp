#include <bits/stdc++.h>

using namespace std;

#define sz 100007

vector<int> g[sz];
vector<bool> used(sz, false);
int color[sz];
bool flag = true;
vector<int> d(sz, INT_MAX);
vector<int> e(sz, -1);

void bfs(int v) {
    queue<int> q;
    q.push(v);
    used[v] = true;
    d[v] = 0;
    e[v] = -1;
    while (q.size() > 0) {
        int x = q.front();
        q.pop();
        for (int y : g[x]) {
            if (used[y] == false) {
                q.push(y);
                used[y] = true;
                d[y] = d[x] + 1;
                e[y] = x;
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    int from, to;
    cin >> from >> to;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(from);

    if (d[to] == INT_MAX) {
        cout << -1;
        return 0;
    }

    cout << d[to] << "\n";

    vector<int> path;

    while (to != -1) {
        path.push_back(to);
        to = e[to];
    }

    reverse(path.begin(), path.end());

    for (int i : path) cout << i << " ";
    
    
    return 0;
}