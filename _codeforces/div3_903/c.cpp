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


    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool used[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[i][j] = false;
        }
    }   

    ll res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (used[i][j] == false) {
                int i1 = i, j1 = j;
                int i2 = n - 1 - i, j2 = n - 1 - j;
                int i3 = j, j3 = n - 1 - i;
                int i4 = n - 1 - i3, j4 = n - 1 - j3;

                used[i1][j1] = true;
                used[i2][j2] = true;
                used[i3][j3] = true;
                used[i4][j4] = true;

                char c1 = a[i1][j1], c2 = a[i2][j2], c3 = a[i3][j3], c4 = a[i4][j4];
                char c = max(max(c1, c2), max(c3, c4));

                res += c - c1;
                res += c - c2;
                res += c - c3;
                res += c - c4;
            }
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

