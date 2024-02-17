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

ll func(int l, int r, vector<ll> &a) {
    ll res = *max_element(a.begin() + l, a.begin() + r + 1);
    ll cur = 0;

    int j = l;
    for (int i = l; i <= r; i++) {
        cur += a[i];
        while (j < i and a[j] <= 0) {
            cur -= a[j];
            j++;
        }
        res = max(cur, res);
    }
    return res;
}


ll maxSubArray(int l, int r, vector<ll>& a) {
        ll res = *max_element(a.begin() + l, a.begin() + r + 1);
        ll cur = 0;
        for (int i = l; i <= r; i++) {
            if (cur < 0) {
                cur = 0;
            }
            cur += a[i];
            
            res = max(res, cur);
        }
        
        
        return res;
    }


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = *max_element(all(a));
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n - 1 and abs(a[j + 1]) % 2 != abs(a[j]) % 2) {
            j++;
        }
        // cout << "i: " << i << "  j: " << j << "\n";
        res = max(res, maxSubArray(i, j, a));
        i = j + 1;
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

