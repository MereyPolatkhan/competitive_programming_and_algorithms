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
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    // cout << "l: " << l << "  r: " << r << "  a: ";
    // for (int i : a) {
    //     cout << i << " ";
    // }
    // cout << "\n";


    ll res = 0;

    for (int i = 0; i < n; i++) {
        int from = lower_bound(a.begin() + i, a.end(), l - a[i]) - (a.begin() + i);
        int end = upper_bound(a.begin() + i, a.end(), r - a[i]) - (a.begin() + i);
        if (from >= end) {
            continue;
        }
        if(l - a[i] <= a[i] and a[i] <= r - a[i]) 
            res--;
        // cout << from << " - " << end << "\n";
        res += end - from;
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

