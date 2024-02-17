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
    int n, r;
    cin >> n >> r;

    vector<int> a(n);

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    int cnt = 0;
    int x = 0;
    while (x < n) {
        int pos = -1;
        for (int j = max(0, x - r + 1); j <= min(x + r - 1, n - 1); j++)
            if (a[j] == 1) 
                pos = j;
         

        if (pos == -1) {
            cout << -1 << "\n";
            return;
        }
        cnt++;
        x = pos + r;
    }
    cout << cnt << "\n";
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
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

