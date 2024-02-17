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
    int n, m;
    cin >> n >> m;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x % m]++;
    }

    int res = 0;



    for (auto &it: mp) {
        int x = it.first;
        int cnt = it.second;

        if (x == 0) {
            res++;
        }
        else if (x * 2 == m) {
            res++;
        }
        else if (mp.count(m - x) and x < m - x) {
            int a = mp[x];
            int b = mp[m - x];

            if (a < b) {
                swap(a, b);
            }

            if (a == b) 
                res++;
            else {
                a -= (b + 1);
                res += (1 + a);
            }
        }   
        else if (!mp.count(m - x)) {
            res += mp[x];
        }
    }

    cout << res << "\n";


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

