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
    string a, b;
    cin >> a >> b;

    if (n == 1) {
        cout << (a[0] != b[0]) << "\n"; 
        return;
    }

    int i, j;
    i = 0;
    j = n - 1;

    int cnt = 0;

    while (i < j) {
        map<char, int> mp;
        mp[a[i]]++, mp[a[j]]++, mp[b[i]]++, mp[b[j]]++;
        
        if (mp.size() == 4) {
            cnt += 2;
        }
        else if (mp.size() == 3) {
            cnt += 1;
            if (a[i] == a[j]) 
                cnt += 1;
        }
        else {
            for (auto &it: mp) {
                if (it.second % 2) {
                    cnt += 1;
                    break;
                }
            }
        }

        i++;
        j--;

        if (i == j and a[i] != b[i]) 
            cnt++;
    }

    cout << cnt << "\n";
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

