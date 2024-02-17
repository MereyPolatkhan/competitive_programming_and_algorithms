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
  
typedef unsigned long long ll;

void solve() {
    ll n;
    cin >> n;

    if (n <= 5) {
        cout << 1 << "\n";
        return;
    }

    ll it = 6;
    ll h = 1;
    ll sum = 6;
    while (sum <= n) {
        sum = it * 3 + 1;
        it = it * 3;
        h++;
    }

    cout << h << "\n";
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
    #else
    freopen("aztec.in", "r", stdin);
    freopen("aztec.out", "w", stdout);
    #endif


    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

