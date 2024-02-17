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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(all(s));

    if (count(all(s), s[0]) < k) {
        cout << s[k - 1] << "\n";
        return;
    }   

    if (s[k] != s.back()) {
        cout << s[0] << s.substr(k) << "\n";
    }
    else {
        cout << s[0];
        for (int i=0;i<(n-k+k-1)/k;i++)
        cout<<s[n-1];

        cout << "\n";
    }
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


