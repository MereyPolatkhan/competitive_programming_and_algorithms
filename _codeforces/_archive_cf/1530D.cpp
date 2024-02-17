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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> res = a;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (mp[res[i]] >= 2 and mp.count(i)) {
            mp[res[i]]--;
            res[i] = 0;
        }
    }



    for (int i = 1; i <= n; i++) {
        if (mp[res[i]] >= 2) {
            mp[res[i]]--;
            res[i] = 0;
        }
    }




    // for (int i = 1; i <= n; i++) {
    //     cout << res[i] << " ";
    // }
    // cout << "\n";

    // for (auto it: mp) {
    //     cout << it.first << ": " << it.second << "\n";
    // }
    // cout << "\n";
    // return;

    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        st.erase(a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (res[i])
            continue;
    
        for (int x: st) {
            if (x != i) {
                res[i] = x;
                break;
            }
        }
        st.erase(res[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (res[i] == a[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    cout << "\n";
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
