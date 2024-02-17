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

int const p = 31;

vector<ull> hashing(string s) {
    int n = s.size();
    vector<ull> h(n + 1);

    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * p + s[i - 1];
    }

    return h;
}


ull calc_hash(int l, int r, vector<ull> & h, vector<ull> & powers) {
    return h[r + 1] - h[l] * powers[r - l + 1];
}

bool check(int len, vector<vector<ull>> & hashes, vector<ull> & powers, ull &reshash) {   
    map<ull, int> mp;
    int n = hashes.size();
    for (vector<ull> & h: hashes) {
        set<ull> st;
        for (int i = 0; i < h.size() - len; i++) {
            int l = i;
            int r = i + len - 1;
            st.insert(calc_hash(l, r, h, powers));
        }

        for (const ull &y: st) {
            mp[y]++;
        }
    }


    for (auto &it: mp) {
        if (it.second == n) {
            reshash = it.first;
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    int minlen = 1e9, maxlen = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minlen = min(minlen, (int)a[i].size());
        maxlen = max(maxlen, (int)a[i].size());
    }

    vector<vector<ull>> hashes(n);
    for (int i = 0; i < n; i++) {
        hashes[i] = hashing(a[i]);
    }

    vector<ull> powers(maxlen + 1);
    powers[0] = 1;
    for (int i = 1; i < powers.size(); i++) {
        powers[i] = powers[i - 1] * p;
    }

    int l = 0 - 1, r = minlen + 1;
    ull reshash = -1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (check(mid, hashes, powers, reshash)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (reshash == -1) {
        cout << "";
    }
    else {
        vector<ull> h = hashes[0];
        for (int i = 0; i < h.size() - l; i++) {
            if (calc_hash(i, i + l - 1, h, powers) == reshash) {
                cout << a[0].substr(i, l);
                return;
            }

        }
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
    #else
    freopen("substr3.in", "r", stdin);
    freopen("substr3.out", "w", stdout);
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

