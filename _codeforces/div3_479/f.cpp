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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> mp;
    int index = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        // mp[a[i]] = max(mp[a[i]], mp[a[i] - 1] + 1);
        if (mp[a[i]] < mp[a[i] - 1] + 1) {
            mp[a[i]] = mp[a[i] - 1] + 1;
        }
        if (mp[a[i]] > mx) {
            mx = mp[a[i]];
            index = i;
        }
    }


    vector<int> res;
    res.pb(index);
    int x = a[index];

    for (int i = index - 1; i >= 1; i--) {
        if (a[i] + 1 == x) {
            res.pb(i);
            x = a[i];
        }
    }


    reverse(all(res));

    cout << res.size() << "\n";
    for (int &x: res)   
        cout << x << " ";
    cout << "\n";
    
    
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

