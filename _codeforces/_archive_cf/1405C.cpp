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

int n, k;
string s;

bool check(map<char, int> &mp) {
    return mp['1'] <= k / 2 and mp['0'] <= k / 2;
}


void solve() {
    cin >> n >> k;
    cin >> s;


    for (int l = 0, r = k; r < n; l++, r++) {
        if (s[l] != '?' and s[r] != '?') {
            if (s[l] != s[r]) {
                cout << "NO\n";
                return;
            }
        }
        else {
            if (s[l] != '?')
                s[r] = s[l];
            else 
                s[l] = s[r];
        }
    }

    
    map<char, int> mp;
    for (int i = 0; i < k; i++) {
        mp[s[i]]++;
    }
    if (check(mp) == false) {
        cout << "NO\n";
        return;
    }
    for (int l = 0, r = k; r < n; l++, r++) {
        mp[s[l]]--;
        mp[s[r]]++; 
        if (check(mp) == false) {
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