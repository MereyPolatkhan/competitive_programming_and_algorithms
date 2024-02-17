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
    vector<int> b(n);
    multiset<pii> st; 
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        st.insert({a[i], b[i]});
    }

    sort(all(a));
    sort(all(b));


    int res1 = b[0] - a[n - 2];
    int res2 = b[1] - a[n - 1];
    int res3 = 0;
    if (st.count({a[n-1], b[0]})) {
        res3 = b[1] - a[n - 2];
    }
    cout << max(res1, max(res2, res3)) << "\n";

    

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

