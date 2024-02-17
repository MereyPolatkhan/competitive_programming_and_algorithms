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

    int n, m;
    cin >> n >> m;

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x].pb(i);
    }

    int l = n;
    int r = -1;

    for (auto &it: mp) {
        if (m == 0) {
            break;
        }
        if (it.second.size() <= m) {
            l = min(l, it.second[0]);
            r = max(r, it.second.back());
            m -= it.second.size();

            if (m == 0) 
                break;
        }
        else if (l == n and r == -1) {
            vector<int> a = it.second;
            l = 0;
            r = m - 1;

            int res = INT_MAX;

            while (r < a.size()) {
                res = min(res, a[r] - a[l] + 1);
                r++;
                l++;
            }
            cout << res << "\n";
            return;
        }
        else {
            int cnt = 0;
            vector<pii> d;
            for (int & index: it.second) {
                if (index < l) {
                    d.pb({l - index, 0});
                }
                else if (l <= index and index <= r) {
                    cnt++;
                }
                else {
                    d.pb({index - r, 1});
                }
            }

            if (m <= cnt) {
                break;
            }
            
            sort(all(d));

            for (pii &dest: d) {
                if (m == 0) {
                    break;
                }

                if (dest.second == 0) { // l
                    l -= dest.first;
                }
                else if (dest.second == 1) { // r
                    r += dest.first;
                }
                m--;
            }
        }
    }

    cout << r - l + 1 << "\n";
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

    solve();


    return 0;
}

