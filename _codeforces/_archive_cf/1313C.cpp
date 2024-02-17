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

ll func(int index, vector<int> &a) {
    int l = index - 1, r = index + 1;
    ll left_min = a[index], right_min = a[index];
    ll res = 0;
    while (l >= 0) {
        left_min = min(left_min, (ll)a[l]);
        res += a[l] - left_min;
        l--;
    }
    while (r < a.size()) {
        right_min = min(right_min, (ll)a[r]);
        res += a[r] - right_min;
        r++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a)
        cin >> x;

    ll sum = LLONG_MAX;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if ((i == 0 or i == n - 1) or (a[i - 1] <= a[i] and a[i] >= a[i + 1])) {
            ll cur = func(i, a);
            if (cur < sum) {
                sum = cur, index = i;
            }
        }
    }

    // cout << sum << " " << index << "\n";
    int l = index - 1, r = index + 1;
    ll left_min = a[index], right_min = a[index];
    while (l >= 0) {
        left_min = min(left_min, (ll)a[l]);
        a[l] = left_min;
        l--;
    }
    while (r < a.size()) {
        right_min = min(right_min, (ll)a[r]);
        a[r] = right_min;
        r++;
    }
    
    for (auto x: a) 
        cout << x << " ";
    cout << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
