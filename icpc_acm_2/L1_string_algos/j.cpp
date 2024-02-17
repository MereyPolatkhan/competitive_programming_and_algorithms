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


bool cmp(string a, string b) {
    return a.size() > b.size();
}

void solve() {
    const int p = 31;
    int n;
    cin >> n;
    
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a), cmp);

    set<ull> st;

    for (int j = 0; j < n; j++) {   
        string s = a[j];

        vector<ull> temp;
        ull h = 0;
        
        for (int i = 0; i < s.size(); i++) {
            h = h * p + s[i];
            temp.pb(h);
        }

        if (st.count(h)) {
            cout << "vulnerable\n";
            return;
        }
        for (ull &x: temp) {
            st.insert(x);
        }
    }

    cout << "non vulnerable\n";
}





void solve_brute_force() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a), cmp);
    
    set<string> st;


    for (int j = 0; j < n; j++) {
        string s = a[j];
        if (st.count(s)) {
            cout << "vulnerable\n";
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            st.insert(s.substr(0, i + 1));
        }
    }

    cout << "non vulnerable\n";

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
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
        // solve_brute_force();
    }

    return 0;
}
