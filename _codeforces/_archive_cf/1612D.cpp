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



void solve() {
    cout << "\n\n\n";
    ll a, b, x;
    cin >> a >> b >> x;

    while (a and b and (a >= x or b >= x)) {
        if (a < b)
            swap(a, b);

        // cout << "a: " << a << " b: " << b  << " x: " << x << "\n";
        if (a != x and b != x and (a - x) % b) {
            a %= b;
        }
        else {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() { 
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
