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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    vector<int> b, r;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            r.pb(a[i]);
        }
        else {
            b.pb(a[i]);
        }
    } 
    
    sort(rall(r));
    sort(all(b));

    int j = 1;

    vector<int> used(n + 1, false);

    for (int x: b) {
        if (j <= x) {
            used[j] = true;
            j++;
        }
        else {
            break;
        }
    }

    j = n;
    for (int x: r) {
        if (j >= x) {
            used[j] = true;
            j--;
        }
        else {
            break;
        }
    }

    if (count(all(used), true) == n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}





int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

