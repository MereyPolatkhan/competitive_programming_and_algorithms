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

bool cmp(pii a, pii b) {
    return a.first - a.second > b.first - b.second;
}

void solve() {

    int n; ll m;
    cin >> n >> m;

    vector<pii> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
    }   



    if (sum <= m) {
        cout << 0 << "\n";
        return;
    }

    sort(all(a), cmp);
    // cout << "sum : " << sum << "\n";
    // for (auto it: a)
    //     cout << it.first << " " << it.second << "\n";
    // cout << "\n";
    // return;



    int cnt = 0;
    for (auto &it: a) {
        sum -= (it.first - it.second);
        cnt++;

        if (sum <= m) 
            break;
    }

    if (sum <= m) 
        cout << cnt << "\n";
    else 
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
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

