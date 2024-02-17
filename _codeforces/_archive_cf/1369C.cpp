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

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(rall(a));  
    
    multiset<int> st;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    ll res = 0;
    int l = 0, r = n - 1;
    while (st.count(1)) {
        res += a[l] * 2;
        l++;
        st.erase(st.find(1));
    }

    while (l < r) {
        int x = *st.rbegin();
        st.erase(st.find(x));
        res += a[l++];
        res += a[r--];
        x -= 2;
        while (x--) {
            r--;
        }
    }
    cout << res << "\n";
}



int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}