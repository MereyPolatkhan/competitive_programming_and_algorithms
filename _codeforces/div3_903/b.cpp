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
    multiset<int> st;

    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;

        st.insert(x);
    }   

    // cout << "st: "; for (int i: st) cout << i << " "; cout << "\n";

    for (int i = 0; i < 3; i++) {
        int end = *st.rbegin();
        int begin = *st.begin();

        st.erase(st.find(end));

        st.insert(end - begin);
        st.insert(begin);

    }

    
    set<int> settik;
    for (int i: st) {
        if (i)
            settik.insert(i);
    }
    if (settik.size() <= 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

