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

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    
    set<ll> st;
    st.insert(0);

    ll sum = 0;
    int cnt = 0;
    
    for (ll &x: a) {
        sum += x;
        // cout << "x: " << x << "\n";
        // cout << "sum: " << sum << "\nst: ";
        // for (ll x: st) cout << x << " "; cout << "\n\n";
        if (st.count(sum)) {
            cnt++;
            // cout << "cnt: " << cnt << "\n\n\n";
            st.clear();
            
            sum = x;
            st.insert(0);
            st.insert(x);
        }    
        st.insert(sum);
    }

    cout << cnt << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
