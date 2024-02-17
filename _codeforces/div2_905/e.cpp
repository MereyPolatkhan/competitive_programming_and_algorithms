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

ull binpow(ull a, ull n) {
    if (n == 0) {
        return 1LL * 1;
    }
    else if (n % 2 == 0) {
        ull b = binpow(a, n / 2);
        return b * b;
    }
    else {
        return binpow(a, n - 1) * a;
    }
}

void solve_() {
    int n;
    cin >> n;

    vector<ull> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ull res = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {

            ull raz = ceil((double)a[i] / (double)a[i + 1]);
            ull lg = ceil(log2(raz));


            res += lg;

            a[i + 1] = a[i + 1] * binpow(2, lg);
        }
    }

    cout << res << "\n";
}

void solve() {
    int n;
    cin >> n;

    vector<double> a(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = (log2(x));
    }

    ll res = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            double delta = (a[i] - a[i + 1]);
            ll d = delta;

            if ((double)d != delta) {
                d++;
            }

            res += d;


            a[i + 1] += (d);
        }

        
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
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

