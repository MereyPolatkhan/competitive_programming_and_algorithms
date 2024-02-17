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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];


    // cout << "a: "; for (int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
    // cout << "b: "; for (int i = 0; i < n; i++) cout << b[i] << " "; cout << "\n"; 

    for (int i = 1; i < n; i++) {
        a[i] = min(a[i], a[i - 1]);
    }
    for (int i = 1; i < n; i++) {
        b[i] = max(b[i], b[i - 1]);
    }

    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int index = lower_bound(all(b), a[i]) - b.begin();
        res = min(res, i + index);

        // cout << "a[i]: " << a[i] << "   index: " << index << "\n";
    }

    cout << res << "\n";
    return;
    cout << "a: "; for (int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
    cout << "b: "; for (int i = 0; i < n; i++) cout << b[i] << " "; cout << "\n"; 

    cout << "\n\n\n";

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