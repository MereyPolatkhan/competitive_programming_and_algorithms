#include <bits/stdc++.h>
using namespace std;

int const BIG = 1e9;
int const MAXN = 1e5 + 5;

vector<pair<int, int> > g[MAXN];

int n, m;

vector<int> dijkstra(int s){
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


        for(int j = 0; j < g[u].size(); j++){
            p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > d[u] + w){
                // pair<int, int> p2 = *(setik.find(make_pair(d[v], v)));
                setik.erase(make_pair(d[v], v));
                d[v] = d[u] + w;
                setik.insert(make_pair(d[v], v));
            }
        }

    }
    return d;

}

int main(){

    int res = 0;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        g[x].push_back({y, l});
        g[y].push_back({x, l});
    }
    
    int redRidingHood, merchant, pharmacy, grandmother;
    cin >> redRidingHood >> merchant >> pharmacy >> grandmother;

    vector<int> d = dijkstra(redRidingHood);

    int red_merch = d[merchant];
    int red_pharm = d[pharmacy];

    d = dijkstra(merchant);
    
    int merch_pharm = d[pharmacy];
    int merch_grand = d[grandmother];

    d = dijkstra(pharmacy);

    int pharm_merch = d[merchant];
    int pharm_grand = d[grandmother];

    if (red_merch < BIG and merch_pharm < BIG and pharm_grand < BIG) {
        if (red_pharm < BIG and pharm_merch < BIG and merch_grand < BIG) {
            cout << min(red_merch + merch_pharm + pharm_grand, red_pharm + pharm_merch + merch_grand);
            return 0;
        }
    }
    else cout << -1;


    return 0;
}

