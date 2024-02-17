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
    int n, m;
    cin >> n >> m;

    map<int, set<int>> mp;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a > b)  
            swap(a, b);

        mp[a].insert(b);
    }

    int q;
    cin >> q;
    
    while (q--) {
        int w;
        cin >> w;
        if (w == 1) {
            cin >> a >> b;
            if (a > b) 
                swap(a, b);
            mp[a].insert(b);
        }
        else if (w == 2) {
            cin >> a >> b;
            if (a > b) 
                swap(a, b);
            mp[a].erase(b);
            if (mp[a].size() == 0) {
                mp.erase(a);
            }
        }
        else {
            cout << n - mp.size() << "\n";
        }        
    }
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

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
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}