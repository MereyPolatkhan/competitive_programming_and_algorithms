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



vector<string> a;

void precalc() {
    for (int i = 0; i <= 62; i++) {
        a.pb(to_string((ll)pow(2, i)));
    }
}

int func(string &p, string &n) {
    int cnt = 0;
    int i = 0;
    int j = 0;


    while (i < p.size() and j < n.size()) {
        if (p[i] != n[j]) {
            j++;
            cnt++;
        }
        else {
            i++;
            j++;
        }
    }

    cnt += p.size() - i;
    cnt += n.size() - j;
    // cout << p << " " << cnt << "\n";
    return cnt;
}

void solve() {
    string n;
    cin >> n;

    int res = INT_MAX;
    for (string &powers: a) {
        res = ::min(res, func(powers, n));
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

    precalc();


    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }


    return 0;
}
