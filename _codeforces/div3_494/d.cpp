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


int func(vector<pii> &a, int b) {
    int cnt = 0;
    for (pii &p: a) {
        if (p.first <= b) {
            int k = b / p.first;
            k = min(k, p.second);
            b -= (k * p.first);
            cnt += k;
        }

        if (b <= 0) {
            break;
        }
    }

    if (b == 0)     
        return cnt;
    else 
        return -1;
}


void solve() {

    int n, q;
    cin >> n >> q;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<pii> a;

    for (auto &it: mp) {
        a.pb({it.first, it.second});
    }

    sort(rall(a));

    // for (auto &it: a) 
    //     cout << it.first << ": " << it.second << "\n";

    // cout << "\n";



    while (q--) {
        int b;
        cin >> b;

        cout << func(a, b) << "\n";
        
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

