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

vector<string> generate(string s) {
    vector<string> res;
    string copys = s;
    for (char i = 'a'; i <= 'k'; i++) {
        if (i != s[0]) {
            copys[0] = i;
            res.pb(copys);
        }
    }
    copys = s;
    for (char i = 'a'; i <= 'k'; i++) {
        if (i != s[1]) {
            copys[1] = i;
            res.pb(copys);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll cnt = 0;
    map<string, int> mp;
    for (int i = n - 1; i >= 0; i--) {
        vector<string> g = generate(a[i]);
        for (int i = 0; i < g.size(); i++) {
            if (mp.count(g[i])) {
                cnt += mp[g[i]];
            }
        }
        mp[a[i]]++;
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

