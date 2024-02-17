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

int const N = (int)2e5;
vector<map<int, int>> a(N + 1);

void putBits(int x, map<int, int> &mp) {
    vector<int> b;
    while (x) {
        b.pb(x % 2);
        x /= 2;
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) {
            mp[i + 1]++;
        }
    }
    return;
}

void precalc() {
    map<int, int> mp;
    for (int i = 0; i <= N; i++) {
        putBits(i, mp);
        a[i] = mp;
    }
}

void solve() {
    int l, r;
    cin >> l >> r;


    map<int, int> mp = a[r];

    for (auto &it: a[l - 1]) {
        mp[it.first] -= it.second;
    }    


    int delta = r - l + 1;

    int res = 1e9;
    for (auto &it: mp) {
        res = min(res, delta - it.second);
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
    #endif

    precalc();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }


    return 0;
}
