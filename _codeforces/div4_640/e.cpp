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

vector<usi> a;
unordered_map<usi, usi> mp;

void solve() {
    usi n;
    cin >> n;

    a.resize(n + 1);
    mp.clear();
    for (usi i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    usi cnt = 0;
    for (usi i = 1; i <= n; i++) {
        int pf = a[i];
        for (usi j = i + 1; j <= n; j++) {
            pf += a[j];
            if (pf > n) {
                break;
            }
            if (mp[pf]) {
                cnt += mp[pf];
                mp[pf] = 0;
            }
        }
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

