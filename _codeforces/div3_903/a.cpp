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


vector<int> p_f(string s) { // O(n)
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[i] == s[j]) 
            j = j + 1;
        p[i] = j;
    }
    return p;
}


bool check(string t, string s) {
    string q = t + '&' + s;
    vector<int> p = p_f(q);

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == t.size()) {
            return true;
        }
    }
    return false;
}


void solve() {
    int n, m;
    cin >> n >> m;


    string s, t;
    cin >> s >> t;

    if (check(t, s)) {
        cout << 0 << "\n";
        return;
    }

    if (s.size() >= t.size()) {
        int cnt = 0;
        s += s;
        cnt++;

        if (check(t, s)) {
            cout << cnt << "\n";
            return;
        }
    }
    else {
        int cnt = 0;
        while (s.size() < t.size() * 2) {
            s += s;
            cnt++;
            if (check(t, s)) {
                cout << cnt << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

