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


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum_a = 0, prev_a = 0;
    int sum_b = 0, prev_b = 0;
    int cnt = 0;

    int i = 0;
    int j = n - 1;
    bool done;
    while (i <= j) {
        done = false;
        while (i <= j and prev_a <= prev_b) {
            sum_a += a[i];
            prev_a += a[i];
            i++;
            done = true;
        }
        if (done) cnt++;

        prev_b = 0;
        done = false;
        while (i <= j and prev_a >= prev_b) {
            prev_b += a[j];
            sum_b += a[j];
            j--;
            done = true;
        }
        if (done) cnt++;
        prev_a = 0;
    }
    cout << cnt << " " << sum_a << " " << sum_b << "\n";

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
    freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

