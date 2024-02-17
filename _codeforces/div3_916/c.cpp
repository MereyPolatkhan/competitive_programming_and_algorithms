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



void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        b[i] = max(b[i], b[i - 1]);
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (k == 0) 
            break;
        ll cur = a[i] + (k - 1) * b[i];
        res = max(res, cur);
        k--;
    }
    cout << res << "\n";

    // cout << "k: " << k << "\n";
    // cout << "a: "; for (int x: a) cout << x << " "; cout << "\n";
    // cout << "b: "; for (int x: b) cout << x << " "; cout << "\n";   
    // cout << "\n\n";

}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

