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

bool check1(string s) {
    int n = s.size();
    vector<bool> used(n, false);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'A' and s[i + 1] == 'B') {
            used[i] = true;
            used[i + 1] = true;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (used[i] or used[i + 1])
            continue;

        if (s[i] == 'B' and s[i + 1] == 'A') {
            used[i] = true;
            used[i + 1] = true;
            break;
        }
    }

    return (count(all(used), true) == 4);
}

bool check2(string s) {
    int n = s.size();
    vector<bool> used(n, false);

    for (int i = 0; i < n - 1; i++) {
        if (used[i] or used[i + 1])
            continue;

        if (s[i] == 'B' and s[i + 1] == 'A') {
            used[i] = true;
            used[i + 1] = true;
            break;
        }
    }


    for (int i = 0; i < n - 1; i++) {
        if (used[i] or used[i + 1])
            continue;

        if (s[i] == 'A' and s[i + 1] == 'B') {
            used[i] = true;
            used[i + 1] = true;
            break;
        }
    }



    return (count(all(used), true) == 4);
}

void solve() {
    string s;
    cin >> s;
    if (check1(s) or check2(s)) 
        cout << "YES\n";
    else 
        cout << "NO\n";
}   

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
