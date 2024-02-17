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


int it = 0;
void solve() {
    ++it;
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    if (n0 and n2) {
        n1--;
    }
    int begin = 0;
    if (n0) {
        for (int i = 0; i < n0 + 1; i++) {
            cout << 0;
        }
        begin = 1;
    }
    if (n2) {
        for (int i = 0; i < n2 + 1; i++) {
            cout << 1;
        }
        begin = 0;
    }
    if (!n0 and !n2) {
        n1++;
    }
    for (int i = 0; i < n1; i++) {
        cout << begin;
        begin = 1 - begin;
    }

    cout << "\n";    
}


/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

