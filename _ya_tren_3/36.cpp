#include <bits/stdc++.h>


using namespace std;

#define N 100009
#define M 100009

int n;
vector<int> g[N];
vector<int> used(N, 0);
vector<int> d(N, 1e9);


void bfs(int v) {
    used[v] = 1;
    queue<int> q;
    q.push(v);
    d[v] = 0;

    while (q.size() > 0) {
        int x = q.front();
        q.pop();
        for (int y : g[x]) {
            if (used[y] == 0) {
                q.push(y);
                used[y] = 1;
                d[y] = min(d[y], d[x] + 1);
                // d[y] = d[x] + 1;
            }
        }
    } 
}


int main() {    

    cin >> n;
    int a[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int from, to;
    cin >> from >> to;

    bfs(from);

    // for (int i = 1; i <= n; i++) {
    //     cout  << i  << " " << d[i] << "\n";
    // }

    if (d[to] >= 1e8) {
        cout << -1;
    }
    else {
        cout << d[to];
    }

    return 0;
}