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
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(i + 1);
    }

    vector<int> b(n);
    b[0] = a[0];

    int i = 1;
    while (i < n) {
        while (i < n and a[i - 1] == a[i]) 
            i++;

        if (i < n)
            b[i] = a[i];
        i++;
    }
    
    for (int i = 0; i < n; i++) {
        if (b[i])
            st.erase(b[i]);
    }

    
    vector<int> mn(n), mx(n);
    auto it = st.begin();
    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            mn[i] = *it;
            it++;
        }
        else {
            mn[i] = b[i];
        }
    }

    int y = -1;
    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            it = st.upper_bound(y);
            it--;
            mx[i] = *it; 
            st.erase(it);
        }
        else {
            y = b[i];
            mx[i] = b[i];
        }
    }


    for (int x: mn) {
        cout << x << " ";
    }
    cout << "\n";
    for (int x: mx) {
        cout << x << " ";
    }
    cout << "\n\n";

}

int32_t main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
