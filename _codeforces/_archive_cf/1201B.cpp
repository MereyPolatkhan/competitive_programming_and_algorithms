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
    priority_queue<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.push(a[i]);
    }
    

    while (st.size() >= 2) {
        int x = st.top(); st.pop();
        int y = st.top(); st.pop();
        if (x > y)
            swap(x, y);
        
        y -= (x + 1) / 2;
        x -= (x + 1) / 2;
        if (x)
            st.push(x);
        if (y)
            st.push(y);
        // for (int f: st) cout << f << " "; cout << "\n";
    }

    if (st.size())  
        cout << "NO\n";
    else 
        cout << "YES\n";
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
