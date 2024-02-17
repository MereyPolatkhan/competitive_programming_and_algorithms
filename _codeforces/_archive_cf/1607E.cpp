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

    string s;
    cin >> s;

    int i = 0, j = 0;
    int min_i = 0, min_j = 0, max_i = 0, max_j = 0;
    for (int index = 0; index < s.size(); index++) {
        char c = s[index];
        if (c == 'L' and max_j - (j - 1) + 1 <= m) {
            j--;
            min_j = min(min_j, j);
        }
        else if (c == 'R' and (j + 1) - min_j + 1 <= m) {
            j++;
            max_j = max(max_j, j);
        }
        else if (c == 'D' and (i + 1) - min_i + 1 <= n) {
            i++;
            max_i = max(max_i, i);
        }
        else if (c == 'U' and max_i - (i - 1) + 1 <= n) {
            i--;
            min_i = min(min_i, i);
        }
        else {
            break;
        }
    }   

    // cout << "min_i: " << min_i << " max_i: " << max_i << "\n";
    // cout << "min_j: " << min_j << " max_j: " << max_j << "\n";

    cout << min_i * (-1) + 1 << " " << min_j * (-1) + 1 << "\n";
    cout << "\n\n\n";

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
