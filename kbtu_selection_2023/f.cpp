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
  
typedef long long ll;


ll n, p, k, d;

bool func() {
    if (p % n == 0) {
        for (int i = 0; i < n; i++) {
            cout << p / n << "\n";
        }
        return true;
    }
    else {
        cout << "Wrong information\n";
        return false;
    }
}

void solve() {
    cin >> n >> p >> k >> d;
    if (d == 1) {
        bool flag = func();
        if (flag)
            return;
    }
    vector<int> res;

    int zeros = (n - k) + (k - d + 1);

    for (int i = 0; i < zeros; i++) {
        res.pb(0);
    }

    int it = 1;
    int s = p;
    for (int i = 1; i <= d - 1; i++) {
        if (i == d - 1) {
            res.pb(s);
        }
        else {
            res.pb(it);
            s -= it;
            it++;
        }
    }

    sort(rall(res));

    set<int> st;
    for (int i = 0; i < k; i++) {
        st.insert(res[i]);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += res[i];
    }


    if (st.size() == k and sum == p) {
        for (int i: res) {
            cout << i << "\n";
        }
    }
    else {
        cout << "Wrong information\n";
    }
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
    freopen("final.in", "r", stdin);
    freopen("final.out", "w", stdout);
    #endif


    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

