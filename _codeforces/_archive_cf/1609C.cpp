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

int const N = (int)1e6;
vector<int> p(N + 7, true);

void precalc() {
    p[0] = p[1] = false;
    for (int i = 2; i * i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            p[j] = false;
        }
    }
}

void solve() {          
    int n, e;
    cin >> n >> e;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    vector<int> primes;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        if (p[a[i]]) {
            primes.pb(i);
        }
        else if (a[i] == 1) {
            mp[i % e].pb(i);
        }
    }

    ll cnt = 0;

    cout << "primes: "; for (int x: primes) cout << x << " "; cout << "\n";
    cout << "ones: "; for (auto x: mp) for (int y: x.second) cout << y << " "; cout << "\n";
    cout << "\n";


    for (int x: primes) {
        int v = x % e;
        cnt += ((mp[v].size() + 1) * mp[v].size() / 2);
        int index = lower_bound(all(mp[v]), x) - mp[v].begin();
        cout << "x: " << x << "  v: " << v << " index: " << index << "\n";
        if (index == mp[v].size()) {
            cnt -= ((mp[v].size() - 1) * mp[v].size() / 2);
        }
        else {
            int left = index;
            int right = mp[v].size() - index;
            cnt -= ((left - 1) * left) / 2;
            cnt -= ((right - 1) * right) / 2;
        }
    }

    cout << cnt << "\n";
}



int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);

    precalc();

    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}