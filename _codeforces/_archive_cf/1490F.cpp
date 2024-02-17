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


int func(int cnt, unordered_map<int, int> &mp) {
    int res = 0;
    for (auto &it: mp) {
        if (it.second >= cnt) {
            res += it.second - cnt;
        }
        else {
            res += it.second;
        }
    }
    return res;
}

void solve() {   
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    unordered_set<int> st;
    for (auto &it: mp) {
        st.insert(it.second);
    }

    int res = n;
    for (int const &cnt: st) {
        res = min(res, func(cnt, mp));
    }

    cout << res << "\n";
}   




int main() { 
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