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



bool ismini(char c) {
    return 'a' <= c and c <= 'z';
}

void solve() {
    string s;
    cin >> s;

    map<int, char> mp, MP;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            if (MP.size())
                MP.erase(MP.rbegin()->first);
            continue;
        }
        else if (s[i] == 'b') {
            if (mp.size())
                mp.erase(mp.rbegin()->first);
            continue;
        }

        if (ismini(s[i])) {
            mp[i] = s[i];
        }
        else {
            MP[i] = s[i];
        }
    }
    vector<pair<int, char>> a;
    for (auto it: mp) {
        a.pb({it.first, it.second});
    }
    for (auto it: MP) {
        a.pb({it.first, it.second});
    }
    sort(all(a));
    for (auto it: a) {
        cout << it.second;
    }
    cout << "\n";
}


int main() { 
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

