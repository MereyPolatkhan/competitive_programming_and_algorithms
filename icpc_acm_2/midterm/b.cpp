#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


int const N = (int)1e5 + 77;
int const M = (int)2e5 + 77;

int par[N], sz[N];

int get(int a) {
	if (a == par[a])
		return a;
	int pa = get(par[a]);
	par[a] = pa;
	return pa;
}

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	if (sz[b] > sz[a])
		swap(a, b);
	// merge b to a
	par[b] = a;
	sz[a] += sz[b];

}
int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #else
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);



    int n, m;
    cin >> n >> m;

    vector<pair<ll, pii>> g;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.pb({c, {a, b}});
        g.pb({c, {b, a}});
    }

    sort(all(g));


    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    ll res = 0;

    for (auto &it : g) {
        ll cost = it.first;
        int from = it.second.first;
        int to = it.second.second;

        if (get(from) != get(to)) {
            res += cost;

            merge(from, to);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        // cout << "par of " << i << "  is : " << par[i] << "\n";
        if (par[i] == i) {
            cnt++;
        }
    }
    
    if (cnt == 1) {
        cout << res << "\n";
    }
    else {
        cout << "IMPOSSIBLE" << "\n";
    }
    
    return 0;

}

