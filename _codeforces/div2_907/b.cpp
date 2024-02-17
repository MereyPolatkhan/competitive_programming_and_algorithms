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



int get_pow(int x) {
    int cnt = 0;
    while (x % 2 == 0) {
        cnt++;
        x /= 2;
    }
    return cnt;
}


void solve() {
    
    vector<set<int>> cnt(40);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[get_pow(a[i])].insert(i);
    }
    
    while (q--) {
        int x;
        cin >> x;

        for (int i = 1; i <= 33; i++) {
            if (cnt[i].size() and i >= x) {
                vector<int> del;
                for (int j: cnt[i]) {
                    a[j] += (ll)pow(2, x - 1);
                    int pw = get_pow(a[j]);
                    if (pw != i) {
                        cnt[pw].insert(j);
                        del.pb(j);
                    }
                }

                for (int j: del) {
                    cnt[i].erase(j);
                }
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
    cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

