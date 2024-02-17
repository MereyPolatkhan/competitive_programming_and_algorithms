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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

int get_sum(string &s, int l, int r) {
    l--, r--;
    int res = 0;
    for (int i = l; i <= r; i++) {
        char c = s[i];
        res += (int)c - (int)'0';
    }
    return res;
}


ll choose(string s, map<ll, ll> &mp) {
    int n = s.size();

    ll res = 0;

    res += mp[get_sum(s, 1, n)];

    for (int sz = 1; sz <= n / 2; sz++) {
        res += mp[get_sum(s, 1, n - sz) - get_sum(s, n - sz + 1, n)];
    }

    reverse(all(s));
    for (int sz = 1; sz <= n / 2; sz++) {
        res += mp[get_sum(s, 1, n - sz) - get_sum(s, n - sz + 1, n)];
    }
    return res;
}

ll func(vector<string> & a) {

    map<ll, ll> mp;
    for (string &s: a) {
        mp[get_sum(s, 1, s.size())]++;
    }

    ll res = 0;
    for (string &s: a) {
        ll ch = choose(s, mp);
        res += ch;
    }
    return res;
}   

void solve() {
    int n;
    cin >> n;

    vector<string> odd, even;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if ((int)s.size() % 2) {
            odd.pb(s);
        }
        else {
            even.pb(s);
        }
    }

    cout << func(odd) + func(even) << "\n";
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
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

