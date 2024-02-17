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


int ctoi(char c) {
    return (int)c - (int)'0';
}


void solve() {
    string s;
    cin >> s;

    int n = s.size();
      
    for (int i = 0; i < n; i++) {
        if (ctoi(s[i]) % 8 == 0) {
            cout << "YES\n" << s[i] << "\n";
            return;
        }
        for (int j = i + 1; j < n; j++) {
            if ((ctoi(s[i]) * 10 + ctoi(s[j])) % 8 == 0) {
                cout << "YES\n" << s[i] << s[j] << "\n";
                return;
            }
            for (int k = j + 1; k < n; k++) {
                string t = "";
                t += s[i], t += s[j], t += s[k];
                if (stoi(t) % 8 == 0) {
                    cout << "YES\n" << t << "\n";
                    return;
                }
            }
        }
    }
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
