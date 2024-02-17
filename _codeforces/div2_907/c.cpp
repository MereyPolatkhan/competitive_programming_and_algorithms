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
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    

    int l = 0, r = n - 1;
    ll sum = a[l], res = 0;

    while (l + 1 < r) {
        while (l + 1 < r and sum < a[r]) {
            sum += a[++l];
        }        
        
        if (sum >= a[r]) {
            res += a[r] + 1;
            sum -= a[r];
        }
        else {
            res += (sum + a[r] + 1) / 2 + 1;
            sum = 0;
        }

        r--;
    }

    if (l < r) {
        sum += a[r];
    }

    if (sum <= 1) {
        cout << res + sum << "\n";
    }
    else {
        cout << res + (sum + 1) / 2 + 1 << "\n";
    }
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

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

