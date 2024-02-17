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

void solve() {      
    int n;
    cin >> n;

    vector<pii> a(n);
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first, a[i].second = i + 1;
        p[i] = a[i].first;
    }

    sort(rall(a));
    sort(rall(p));
    for (int i = n - 2; i >= 0; i--) {
        p[i] += p[i + 1];
    }

    vector<int> res;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            res.pb(a[i].second);
        }
        else {
            if (p[i] >= a[i - 1].first) {
                res.pb(a[i].second);    
            }   
            else {
                break;
            }
        }
    }



    sort(all(res));
    cout << res.size() << "\n";
    for (int &x: res) {
        cout << x << " ";
    }
    cout << "\n";
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

