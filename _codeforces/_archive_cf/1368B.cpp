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

int const n = 10;
string const cf = "codeforces";
ll k;

void solve() {
    cin >> k;

    ll l = 0, r = 41;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if ((ll)pow(mid, 10) >= k) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    // cout << r << "\n";
    vector<int> a(10, r);
    double res = pow(r, 10);
    for (int i = 0; i < 10; i++) {
        if ((ll)(res / (double)r * (double)l) >= k) {
            res = (ll)(res / (double)r * (double)l);
            a[i] = l;
        }
        else {
            break;
        }
    }

    int i = 0;
    for (ll x : a) {
        while (x--) {
            cout << cf[i];
        }
        i++;
    }
}



int main() { 
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