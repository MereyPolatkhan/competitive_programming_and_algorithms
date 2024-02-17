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
typedef pair<double, double> pii;
typedef unsigned short int usi;


  
vector<int> func(int n) { 

    vector<int> res;

    bool prime[n + 1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p = 3; p <= n; p++) 
        if (prime[p]) 
            res.pb(p);

    return res; 
} 

void base_case(int n, int m, bool swapped) {
    int a[n][m];
    vector<int> nums;
    for (int i = 1; i <= n * m; i++) {
        nums.pb(i);
    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = nums[index++];
        }
    }

    cout << "YES\n";
    if (swapped) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    bool swapped = false;

    if (n > m) {
        swap(n, m);
        swapped = true;
    }

    if (n == 1 and m <= 2) {
        base_case(n, m, swapped);
        return;
    }
    
    vector<int> p = func(n * m);

    if (p.size() % 4 or (n == 1 and m >= 3)) {
        cout << "NO\n";
        return;
    }



    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = -1;
        }
    }



    int cnt = m;
    if (m % 2) {
        cnt--;
    }

    int index = 0;

    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= m; j++) {
            if (index < p.size()) {
                a[i][j] = p[index++];
                a[i + 1][j] = p[index++];
            }
        }
    }

    unordered_set<int> st;
    for (int i: p) {
        st.insert(i);
    }

    vector<int> nums;
    for (int i = 1; i <= n * m; i++) {
        nums.pb(i);
    }
    index = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == -1) {
                while (st.count(nums[index])) {
                    index++;
                }
                a[i][j] = nums[index++];
            }
        }
    }

    cout << "YES\n";
    if (swapped) {
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
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

