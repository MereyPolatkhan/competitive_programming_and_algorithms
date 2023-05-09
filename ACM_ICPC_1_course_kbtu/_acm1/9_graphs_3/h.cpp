#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 7;
typedef pair<int, float> pif;
typedef pair<float, int> pfi;

vector<pif> g[N];
vector<int> pr(N, -1);

vector<float> dijkstra(int src) {
    vector<float> d(N, 1.0);
    priority_queue<pfi, vector<pfi>, greater<pfi> > pq;
    d[src] = 1.0;
    pq.push({0.0, src});

    while (pq.size() > 0) {
        int u = pq.top().second;
        pq.pop();

        for (auto y: g[u]) {
            int v = y.first;
            float w = y.second;
            // cout << w << " " << d[v] << "\n";
            if (d[v] > d[u] * w) {
                d[v] = d[u] * w;
                cout << d[v] << " ";
                pq.push({d[v], v});
                pr[v] = u;
            }
        }
    }
    
    return d;
}


int main() {
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y; float p;
        cin >> x >> y >> p;
        g[x].push_back({y, p / 100.0});        
        g[y].push_back({x, p / 100.0});        
    }

    int src = 1; 
    int finish = n;
    
    vector<float> d = dijkstra(src);
 
    // for (int i = 1; i <= n; i++) cout << d[i] << " ";
    
    return 0;
}