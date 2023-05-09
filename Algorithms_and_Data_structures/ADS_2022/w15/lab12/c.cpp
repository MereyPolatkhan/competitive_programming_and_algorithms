#include <bits/stdc++.h>

using namespace std;

const int BIG = 1e9;
const int MAXN = 1e5 + 5;

vector<pair<int, int> > nugman[MAXN];
vector<pair<int, int> > olzhas[MAXN];

int n, m;


vector<int> dijkstra_nugman(int s){
    set<pair<int, int> > setik;
    vector<int> d(n + 1);

    for(int i = 0; i <= n; i++){
        if(i == s) d[i] = 0;
        else d[i] = BIG;
        setik.insert(make_pair(d[i], i));
    }
    d[s] = 0;
    for(int i = 0; i < n; i++){
        pair<int, int> p = *(setik.begin());
        setik.erase(p);
        int u = p.second, du = p.first;
        if(du == BIG) break;


        for(int j = 0; j < nugman[u].size(); j++){
            p = nugman[u][j];
            int v = p.first, w = p.second;
            if(d[v] > d[u] + w){
                setik.erase(make_pair(d[v], v));
                d[v] = d[u] + w;
                setik.insert(make_pair(d[v], v));
            }
        }

    }
    return d;
}


vector<int> dijkstra_olzhas(int s){
    set<pair<int, int> > setik;
    vector<int> d(n + 1);

    for(int i = 0; i <= n; i++){
        if(i == s) d[i] = 0;
        else d[i] = BIG;
        setik.insert(make_pair(d[i], i));
    }
    d[s] = 0;
    for(int i = 0; i < n; i++){
        pair<int, int> p = *(setik.begin());
        setik.erase(p);
        int u = p.second, du = p.first;
        if(du == BIG) break;


        for(int j = 0; j < olzhas[u].size(); j++){
            p = olzhas[u][j];
            int v = p.first, w = p.second;
            if(d[v] > d[u] + w){
                setik.erase(make_pair(d[v], v));
                d[v] = d[u] + w;
                setik.insert(make_pair(d[v], v));
            }
        }

    }
    return d;
}

int main() {
    cin >> n >> m;

    set<pair<int, int> > temp;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;  
        temp.insert({x, y});
        temp.insert({y, x});

        olzhas[x].push_back({y, 1});
        olzhas[y].push_back({x, 1});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!temp.count({i, j})) {
                // cout << i << " - " << j << "\n";
                nugman[i].push_back({j, 1});
                nugman[j].push_back({i, 1});
            }
        }
    }

    vector<int> nu = dijkstra_nugman(1);
    vector<int> ol = dijkstra_olzhas(1);

    int dist_nug = nu[n];
    int dist_olz = ol[n];

    // cout << "nugman to airport" << dist_nug << "\nolzhas to airport" << dist_olz << "\n"; 

    if (dist_nug >= BIG or dist_olz >= BIG) {
        cout << -1;
    }
    else {
        cout << max(dist_nug, dist_olz);
    }

    return 0;
}