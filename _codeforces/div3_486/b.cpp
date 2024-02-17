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

bool check(string s, string t) {
    if (s.size() < t.size()) {
        return false;
    }
    for (int i = 0; i <= s.size() - t.size(); i++) {
        if (s.substr(i, t.size()) == t) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    vector<pair<int, string>> res;

    for (auto &x: mp) {
        int cnt = 0;
        for (auto &y: mp) {
            if (check(x.first, y.first)) 
                cnt++;
        }
        res.pb({cnt, x.first});
    }

    sort(all(res)); 

    vector<string> b;

    int k = 1;
    for (auto i: res) {
        string s = i.second;
        int cnt = i.first;

        if (cnt == k) {
            k++;
        }
        else {
            cout << "NO\n";
            return;
        }

        for (int j = 0; j < mp[s]; j++) {
            b.pb(s);
        }
    }
    

    cout << "YES\n";

    for (string s: b) {
        cout << s << "\n";
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
    // freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
