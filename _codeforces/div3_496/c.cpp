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

    set<int> powers;
    for (int i = 0; i <= 31; i++) {
        powers.insert(pow(2, i));
    }

    map<int, int> mp;
    for (int &i: a) {
        mp[i]++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (const int &p: powers) {
            if (mp[p - a[i]]) {
                if (p - a[i] == a[i]) {
                    if (mp[a[i]] >= 2)
                        flag = true;
                }
                else {
                    flag = true;
                }
            }
        }
        if (flag == false) {
            cnt++;
        }
    }
    cout << cnt << "\n";
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

