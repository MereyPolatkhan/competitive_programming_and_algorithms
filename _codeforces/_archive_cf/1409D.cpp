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

int ci(char &c) {
    return (int)c - (int)'0';
}

void solve() {
    string s; int d;
    cin >> s >> d;

    reverse(all(s));
    s += '0';
    reverse(all(s));
    
    int sum = 0;
    int j = -1;
    for (int i = 0; i < s.size(); i++) {
        sum += ci(s[i]);
        if (sum > d) {
            j = i;
            break;
        }
    }

    
    if (j == -1) {
        cout << "0\n";
        return;
    }

    while (sum + 1 > d and j - 1 >= 0) {
        // cout << j << "\tsum: " << sum << "\n";
        sum = sum - ci(s[j]);
        j--;
    }

    string san = "";
    for (int i = j + 1; i < s.size(); i++) {
        san += s[i];
    }
    // cout << "j: " << j << "\n";
    ll y = stoll(san);  
    // cout << y << "\n";
    // cout << (ll) pow(10, san.size()) << "\n";
    cout << (ll) pow(10, san.size()) - y << "\n";
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
