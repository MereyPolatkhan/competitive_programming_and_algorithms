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
    ll n, k;
    cin >> n >> k;
    k++;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = pow(10, a[i]);
    }

    vector<ll> cnt(n);
    for (int i = 0; i < n - 1; i++) {
        ll cur_cnt = (a[i + 1] - a[i]) / a[i];
        if (cur_cnt >= k) {
            cnt[i] = k;
            k = 0;
            break;
        }
        else {
            cnt[i] = cur_cnt;
            k -= cur_cnt;
        }
    }

    if (k) {
        cnt.back() = k;
    }
    
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += cnt[i] * a[i];
    }
    cout << res << "\n";
}




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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}

