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


void make_set(int n, vector<int> & par, vector<int> & sz) {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int a, vector<int> & par) {
	if (a == par[a])
		return a;
	int pa = find(par[a], par);
	par[a] = pa;
	return pa;
}

void unite(int a, int b, vector<int> & par, vector<int> & sz) {
	a = find(a, par);
	b = find(b, par);
	if (a == b)
		return;
	if (sz[b] > sz[a])
		swap(a, b);
	// merge b to a
	par[b] = a;
	sz[a] += sz[b];
}




void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<int> apar(n + 1), bpar(n + 1), asz(n + 1), bsz(n + 1);

    make_set(n, apar, asz);
    make_set(n, bpar, bsz);

    for (int i = 1; i <= m1; i++) {
        int x, y;
        cin >> x >> y;
        unite(x, y, apar, asz);
    }

    for (int i = 1; i <= m2; i++) {
        int x, y;
        cin >> x >> y;
        unite(x, y, bpar, bsz);
    }

    vector<pii> res;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find(i, apar) != find(j, apar) and find(i, bpar) != find(j, bpar)) {
                res.pb({i, j});
                unite(i, j, apar, asz);
                unite(i, j, bpar, bsz);
            }
        }
    }

    cout << res.size() << "\n";
    for (pii &it: res) 
        cout << it.first << " " << it.second << "\n";
    
    cout << "\n";
    
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}