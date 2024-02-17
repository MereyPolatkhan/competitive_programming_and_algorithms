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



void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> init_a(n);
    vector<pii> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first, a[i].second = i;
        init_a[i] = a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(rall(a));
    sort(all(b));

    vector<pii> a_max, a_min;
    vector<int> b_max, b_min;

    for (int i = 0; i < n; i++) {
        if (i < x) {
            a_max.pb(a[i]);
            b_min.pb(b[i]);
        }
        else {
            a_min.pb(a[i]);
            b_max.pb(b[i]);
        }
    }


    vector<int> res(n);
    
    sort(all(a_max)), sort(all(b_min));
    for (int i = 0; i < x; i++) {
        pii p = a_max[i];
        res[p.second] = b_min[i];
    }


    sort(all(a_min)), sort(all(b_max));
    for (int i = 0; i < a_min.size(); i++) {
        pii p = a_min[i];
        res[p.second] = b_max[i];
    }

    // check
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (init_a[i] > res[i]) {
            cnt++;
        }
    }
    if (cnt == x) {
        cout << "YES\n";
        for (int i : res) {
            cout << i << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
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
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}

