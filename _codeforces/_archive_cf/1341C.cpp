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


bool check(vector<int> &a, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        if (a[i] == a[i - 1] + 1) 
            continue;
        else 
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }   

    vector<bool> used(n, false);
    for (int index = 1; index <= n; index++) {
        int i = mp[index];
        int j = i;
        while (j + 1 < n and used[j + 1] == false) {
            j++;
        }
        if (j == i or check(a, i, j)) {
            fill(used.begin() + i, used.begin() + (j + 1), true);
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}



int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

