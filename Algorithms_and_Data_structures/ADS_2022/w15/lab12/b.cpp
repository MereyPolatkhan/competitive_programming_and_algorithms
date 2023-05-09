#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll BIG = 1e9;
const ll N = 1e4 + 5;
ll n, m;
ll g[N][N];


vector<ll> dijkstra(ll vertex) {
    vector<bool> used(n + 1, false);
    vector<ll> d(n + 1, BIG);
    d[vertex] = 0;
    for (ll i = 1; i <= n; i++) {
        ll v = -1;
        for (ll j = 1; j <= n; j++) {
            if (used[j] == false && (v == -1 || d[v] > d[j])) {
                v = j;
            }
        }
        used[v] = true;

        for (ll j = 1; j <= n; j++) {
            if (used[j] == false && g[v][j] > 0) {
                if (d[j] > d[v] + g[v][j]) {
                    d[j] = d[v] + g[v][j];
                }
            }
        }
    }
    return d;
}

int main() {
    ll res = 0;
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    
    for (ll i = 0; i < m; i++) {
        ll x, y, l;
        cin >> x >> y >> l;
        g[x][y] = l;
        g[y][x] = l;
    }

    
    ll redRidingHood, merchant, pharmacy, grandmother;
    cin >> redRidingHood >> merchant >> pharmacy >> grandmother;

    vector<ll> d = dijkstra(redRidingHood);

    ll red_merch = d[merchant];
    ll red_pharm = d[pharmacy];

    d = dijkstra(merchant);
    
    ll merch_pharm = d[pharmacy];
    ll merch_grand = d[grandmother];

    d = dijkstra(pharmacy);

    ll pharm_merch = d[merchant];
    ll pharm_grand = d[grandmother];

    if (red_merch < BIG and merch_pharm < BIG and pharm_grand < BIG) {
        if (red_pharm < BIG and pharm_merch < BIG and merch_grand < BIG) {
            cout << min(red_merch + merch_pharm + pharm_grand, red_pharm + pharm_merch + merch_grand);
            return 0;
        }
    }
    else cout << -1;

    return 0;
}