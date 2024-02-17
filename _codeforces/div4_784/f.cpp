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

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    
    int i = -1, j = n;
    int sum_a = 0, sum_b = 0;
    int cnt = 0;
    while (i < j) {
        if (sum_a == sum_b) {
            res = max(res, cnt);
            sum_a += a[++i];
            sum_b += a[--j];
            cnt += 2;
        }
        else if (sum_a < sum_b) {
            sum_a += a[++i];
            cnt++;
        }
        else {
            sum_b += a[--j];
            cnt++;
        }
        // cout << "sums: " << sum_a << " " << sum_b << "\n";
        // cout << "indexes: " << i << " " << j << "\n\n\n";
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

