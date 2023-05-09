#include <bits/stdc++.h>


using namespace std;


const int N = (int)1e5 + 7;
typedef pair<int,int> pii;
vector<pii> g[N];
vector<int> d(N, INT_MAX);


int main() {
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);

    int n, src, finish;
    cin >> n >> src >> finish;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x > 0) {
                g[i].push_back({j, x});
            }
        }
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
            }
        }
    }


    if (d[finish] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << d[finish];
    }


    return 0;
}