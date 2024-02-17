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


bool check(int x, map<int, int> &mp) {
    while (mp.begin()->second == 0) {
        mp.erase(mp.begin());
    }
    int y = mp.begin()->first;
    mp[y]--;
    if (mp[y] == 0) {
        mp.erase(y);
    }

    // int mod = y - x;
    // return mod >= 0 and (y % mod == x);

    return x < ((y + 1) / 2);
}

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<bool> used(n + 1, false);

    for (auto it: mp) {
        if (it.first <= n and !used[it.first]) {
            used[it.first] = true;
            mp[it.first]--;
        }
    }


    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (used[i]) 
            continue;

        if (check(i, mp)) {
            cnt++;
        }
        else{
            cout << -1 << "\n";
            return;
        }
    }
    cout << cnt << "\n";
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

