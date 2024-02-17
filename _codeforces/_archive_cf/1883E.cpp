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
#include <stack>


using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), p(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        ll x = a[i - 1], y = a[i];

        if (x > y) {
            while (x > y) {
                y *= 2;
                p[i]++;
            }
        }
        else {
            while (x * 2 <= y and p[i]) {
                x *= 2;
                p[i]--;
            }
        }
    }
    ll res = 0;
    for (auto &x: p)
        res += x;
    cout << res << "\n";
}   


int main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }


    return 0;
}
