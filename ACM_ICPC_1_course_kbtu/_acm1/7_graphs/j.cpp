#include <bits/stdc++.h>

using namespace std;

#define sz 100007

int n, m;
vector<int> g[sz];
vector<bool> used(sz, false);
int color[sz];
bool flag = true;
vector<int> d(sz, INT_MAX);


void bfs(int v) {
    queue<int> q;
    q.push(v);
    used[v] = true;
    d[v] = 0;
    while (q.size() > 0) {
        int x = q.front();
        q.pop();
        for (int y : g[x]) {
            if (used[y] == false) {
                q.push(y);
                used[y] = true;
                d[y] = d[x] + 1;
            }
        }
    }
}


int main() {
    cin >> n;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int from, to;
    cin >> from >> to;

    bfs(from);

    if (d[to] == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << d[to] << "\n";
    }

    return 0;
}