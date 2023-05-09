#include <bits/stdc++.h>

using namespace std;


int const BIG = 1e9;
int const MAXN = 1e5 + 5;

int n;
vector < pair<int, int> > g[MAXN];


vector<int> dijkstra(int s){
    set<pair<int, int> > setik;
    vector<int> d(n + 1, BIG);
    d[s] = 0;

    for(int i = 1; i <= n; i++){
        setik.insert({d[i], i});
    }

    for(int i = 0; i < n; i++){
        pair<int, int> p = *(setik.begin());
        setik.erase(p);
        int u = p.second, du = p.first;
        if(du == BIG) break;


        for(pair<int, int> p: g[u]){
            int v = p.first, w = p.second;
            if(d[v] > d[u] and d[v] > w){
                setik.erase(make_pair(d[v], v));
                d[v] = max(d[u], w);
                setik.insert(make_pair(d[v], v));
            }
        }

    }
    return d;
}



int main() {
    
    cin >> n;

    vector<pair<int, int> > coord;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coord.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int xi = coord[i].first;
            int yi = coord[i].second;
            int xj = coord[j].first;
            int yj = coord[j].second;

            int w = abs(xi - xj) + abs(yi - yj);
            
            g[i + 1].push_back({j + 1, w});
            g[j + 1].push_back({i + 1, w});

        }
    }

    vector<int> d = dijkstra(1);

    // for (int i = 1; i <= n; i++) {
    //     cout << i << " --- " << d[i] << "\n";
    // }

    cout << d[n];
    return 0;
}