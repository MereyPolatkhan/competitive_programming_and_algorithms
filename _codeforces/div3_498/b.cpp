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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    multiset<int> st;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += pq.top();
        st.insert(pq.top());
        pq.pop();
    }

    vector<int> res; 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (st.count(a[i])) {
            res.pb(++cnt);
            st.erase(st.find(a[i]));
            cnt = 0;
        }
        else {
            cnt++;
        }
    }
    res.back() += cnt;
    cout << sum << "\n";
    for (int &x: res) 
        cout << x << " ";
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

