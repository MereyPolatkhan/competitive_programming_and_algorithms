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
    int n, k;
    cin >> n >> k;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        mp[x]++;
    }

    vector<int> a;
    for (auto &i: mp) {
        if (i.second >= k) 
            a.pb(i.first);
    }
    
    n = a.size();
    if (n == 0) {
        cout << -1 << "\n";
        return;
    }

    // for (int i : a) cout << i << " ";
    // cout << "\n";
    // return;
    
    int i = 0;
    int l = 0, r = 0;

    while (i < n) {
        int j = i;
        while (j + 1 < n and a[j + 1] - a[j] == 1) {
            j++;
        }
        if (a[r] - a[l] < a[j] - a[i]) {
            r = j;
            l = i;
        }
        i = j + 1;
    }

    cout << a[l] << " " << a[r] << "\n";

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

