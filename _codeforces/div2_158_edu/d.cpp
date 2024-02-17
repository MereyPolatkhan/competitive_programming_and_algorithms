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


bool check2(ll x, vector<ll> &a, int n, int index) {
    if (x >= a[index]) {
        x--;
    }
    else {
        return false;
    }

    int l = index - 1, r = index + 1;
    while (l >= 0 and r < n) {
        if (a[l] < a[r]) {
            if (x >= a[l]) {
                x--;
                l--;
            }
            else {
                return false;
            }
        }
        else {
            if (x >= a[r]) {
                r++;
                x--;
            }
            else {
                return false;
            }
        }
    }

    while (l >= 0) {
        if (x >= a[l]) {
            x--;
            l--;
        }   
        else {
            return false;
        }
    }

    while (r < n) {
        if (x >= a[r]) {
            r++;
            x--;
        }
        else {
            return false;
        }
    }

    return true;
}

bool check(ll x, vector<ll> &a, int n, int index, vector<ll> &pf, vector<ll> &sf) {
    if (x >= a[index]) {
        x--;
    }
    else {
        return false;
    }

    int l = index - 1, r = index + 1;
    while (l >= 0 and r < n) {
        if (pf[l] <= sf[r]) {
            if (x >= a[l]) {
                x--;
                l--;
            }
            else {
                return false;
            }
        }
        else {
            if (x >= a[r]) {
                r++;
                x--;
            }
            else {
                return false;
            }
        }
    }

    while (l >= 0) {
        if (x >= a[l]) {
            x--;
            l--;
        }   
        else {
            return false;
        }
    }

    while (r < n) {
        if (x >= a[r]) {
            r++;
            x--;
        }
        else {
            return false;
        }
    }

    return true;
}



void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pf = a, sf = a;
    reverse(all(sf));
    for (int i = 1; i < n; i++) {
        pf[i] += pf[i - 1];
        sf[i] += sf[i - 1];
    }
    reverse(all(sf));



    int mx_index = 0;
    for (int i = 1; i < n; i++) {
        if (a[mx_index] < a[i]) {
            mx_index = i;
        }
    }

    ll l = 0, r = 1e18;

    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid, a, n, mx_index, pf, sf)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << "\n";
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

