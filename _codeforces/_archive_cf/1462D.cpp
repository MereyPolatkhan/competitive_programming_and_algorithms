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

int n;
ll check(ll sum, vector<ll> &a) {
    ll cnt = 0;
    ll temp = 0;
    for (int i = 0; i < n; i++) {
        temp += a[i];
        cnt++;
        if (temp == sum) {
            cnt--;
            temp = 0;
        }
    }
    // cout << "Sum : " << sum << "  cnt : " << cnt  << "  temp: " << temp << "\n";
    if (!temp)
        return cnt;
    return INT_MAX;
}

void solve() {
    cin >> n;

    vector<ll> a(n);
    ll l = INT_MAX, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
        l = min(l, a[i]);
    }


    vector<ll> pref = a;
    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }

    ll res = INT_MAX;
    for (ll i : pref) {
        res = min(res, check(i, a));
    }

    cout << res << "\n";
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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}