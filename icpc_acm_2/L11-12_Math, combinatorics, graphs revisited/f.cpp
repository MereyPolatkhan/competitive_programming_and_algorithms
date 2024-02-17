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
#include <climits>
#include <stack>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

ll const MOD = (ll)1e9 + 7;
int const N = (int)1e5;
map<int, map<int, int>> MP;

map<int, int> factorize(int x) {
    map<int, int> f;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            f[i]++;
            x /= i;
        }
    }
    if (x > 1) 
        f[x]++;
    return f;
}

void precalc() {
    for (int i = 1; i <= N; i++) {
        MP[i] = factorize(i);
    }
}

int mobius(int x) {
    if (x == 1)
        return 1;

    for (auto it: MP[x]) {
        if (it.second >= 2)
            return 0;
    }
    return (int)pow(-1, MP[x].size());
}

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return ((res * res) % MOD * a) % MOD;
    else
        return res * res % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   

    map<int, int> cnt;
    for (int &x: a) {
        for (auto &it: MP[x]) {
            cnt[it.first]++;
        }
    }

    for (auto &it: cnt) {
        cout << it.first << ": " << it.second << "\n";
    }
    cout << "\n";

    ll res = binpow(2, n) - 1; 
    for (auto &it: cnt) {
        int m = mobius(it.first);
        cout << "num: " << it.first << "  m: " << m << "\n";
        res += (m * (binpow(2, it.second) - 1));
    }

    cout << res << "\n";
}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precalc();

    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

