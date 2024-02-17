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
    int k;
    cin >> k;

    vector<vector<int>> ars(k);
    map<int, int> mp;

    vector<int> res(4, 1e9);

    for (int j = 0; j < k; j++) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        
        int sum = 0;
        for (int &x: a) 
            sum += x;
        
        for (int i = 0; i < n; i++) 
            a[i] = sum - a[i];
        

        for (int i = 0; i < n; i++) {
            if (mp.count(a[i])) {
                int index = mp[a[i]];
                res[0] = j + 1;
                res[1] = i + 1;
                res[2] = index + 1;
                for (int c = 0; c < ars[index].size(); c++) {
                    if (ars[index][c] == a[i]) 
                        res[3] = c + 1;
                    
                }
            }
        }


        for (int i = 0; i < n; i++) 
            mp[a[i]] = j;
        
        ars[j] = a; 
    }

    if (res[0] == 1e9) {
        cout << "NO\n";
    }
    else { 
        cout << "YES\n";
        cout << res[0] << " " << res[1] << "\n";
        cout << res[2] << " " << res[3] << "\n";
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
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
