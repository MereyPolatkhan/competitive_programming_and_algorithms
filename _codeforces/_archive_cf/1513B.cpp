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
int const MOD = (int)1e9 + 7;
vector<ll> fac(N + 1);

void precalc() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = (fac[i - 1] * i);
        fac[i] %= MOD;
    }
}
void solve() {  
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min = *min_element(all(a));
    ll cnt_min = count(all(a), min);

    if (cnt_min == 1) {
        cout << 0 << "\n";
        return;
    }   
    for (int x: a) {
        if ((x & min) != min) {
            cout << 0 << "\n";
            return;
        }
    }


    cout << fac[n - 2] * (cnt_min * (cnt_min - 1) % MOD) % MOD << "\n";

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
    precalc();

    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}

