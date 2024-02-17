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

#define FILE

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


int a[1000][1000];
int n, m;

int go(int I, int J) {
    int sum = a[I][J];

    int i = I + 1, j = J + 1;
    while (i < n and j < m) {
        sum += a[i][j];
        i++;
        j++;
    }


    i = I - 1, j = J - 1;
    while (i >= 0 and j >= 0) {
        sum += a[i][j];
        i--;
        j--;
    }


    i = I + 1, j = J - 1;    
    while (i < n and j >= 0) {
        sum += a[i][j];
        i++;
        j--;
    }

    i = I - 1, j = J + 1;
    while (i >= 0 and j < m) {
        sum += a[i][j];
        i--;
        j++;
    }
    
    return sum;

}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = max(res, go(i, j));
        }
    }
    cout << res << "\n";
}


/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef FILE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

