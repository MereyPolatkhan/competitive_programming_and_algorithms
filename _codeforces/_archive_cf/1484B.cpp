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



bool check(int n, int m, int c, vector<int> &a) {
    if (a[0] >= m)
        return false;
    for (int i = 1; i < n; i++) {
        if ((a[i - 1] + c) % m == a[i]) 
            continue;
        else
            return false;
    }   
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a)
        cin >> x;
    
    set<int> st;
    for (int i = 1; i < n; i++) {
        st.insert(a[i] - a[i - 1]);
    }

    if (st.size() <= 1) {
        cout << 0 << "\n";
        return;
    }
    if (st.size() >= 3) {
        cout << -1 << "\n";
        return;
    }
    
    for (int c: st) {
        if (c < 0)
            continue;

        int m = 0;
        for (int i = 1; i < n; i++) {
            m = max(a[i - 1] + c - a[i], m);         
        }
        if (check(n, m, c, a)) {
            cout << m << " " << c << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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
