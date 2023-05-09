#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = int(1e5) * 2 + 7;


vector<pair<ll, pair<ll, ll>>> edges;
int par[N], sz[N];
int n, m;

ll find(ll a){
    if (a == par[a]) {
        return a;
    }
    ll pa = find(par[a]);
    par[a] = pa;
    return pa;
}

void unite(ll a, ll b){
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);

    par[b] = a;

    sz[a] += sz[b];
}

void make(){
    for (ll i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
    }
}

ll sum = 0;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll l, r, c;
        cin >> l >> r >> c;

        edges.push_back({c, {l, r}});
    }

    sort(edges.begin(), edges.end());

    int count = 2;
    while (count <= n) 
        for (auto we: edges) {
            ll x = we.second.first;
            ll y = we.second.second;
            ll w = we.first;

            if (x < count && count <= y) {
                sum += w;
                count++;
                break;
            }
        }
    
    cout << sum;

    return 0;
}