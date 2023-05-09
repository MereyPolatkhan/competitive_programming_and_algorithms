#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 7;
typedef pair<int,int> pii;
vector<pii> g[N];
vector<int> d(N, INT_MAX);
vector<int> pr(N, -1);

int main() {
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);

    int n, m, src, finish;
    cin >> n >> m >> src >> finish;

    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }


    priority_queue<pii, vector<pii>, greater<pii> > pq;
    d[src] = 0;
    pq.push({0, src});

    while (pq.size() > 0) {
        int u = pq.top().second;
        pq.pop();

        for (auto y: g[u]) {
            int v = y.first;
            int w = y.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
                pr[v] = u;
            }
        }
    }

    if (d[finish] == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << d[finish] << "\n";
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << "parent of " << i << " is: " << pr[i] << "\n";
    // }

    vector<int> path;
    while (pr[finish] != -1) {
        path.push_back(finish);
        finish = pr[finish];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    for (int i : path) cout << i << " ";
    return 0;
}