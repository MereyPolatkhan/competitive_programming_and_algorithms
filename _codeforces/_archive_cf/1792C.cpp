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
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[a[i]] = i;
    }

    int l = (n + 1) / 2, r = (n + 1) / 2;
    if (n % 2 == 0) 
        r++;

    // cout << "l : " << l << "   r : " << r << "\n";
    while (l >= 1 and r <= n) {
        if (l == r) {
            l--, r++;
        }
        else if (p[l] < p[l + 1] and p[r - 1] < p[r]) {
            l--, r++;
        }
        else {
            break;
        }
    }

    // cout << "l : " << l << "   r : " << r << "\n";
    // cout << "\n\n\n";

    cout << l << "\n";
}



int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}

