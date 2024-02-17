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
typedef pair<int, int> pii;
typedef unsigned short int usi;



void solve() {      
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> mex;
    for (int i = 0; i <= n; i++) {
        mex.insert(i);
    }

    vector<int> suffix(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (mex.count(a[i])) 
            mex.erase(a[i]);
        
        if (mex.size())
            suffix[i] = (*mex.begin());
        else    
            suffix[i] = (n + 1);
    }   

    // for (int i : a) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for (int i : suffix) {
    //     cout << i << " ";
    // }
    // cout << "\n\n";

    

    vector<int> b;
    int l = 0;
    for (int i = 0; i <= suffix[l]; i++) {
        mex.insert(i);
    }
    for (int r = 0; r < n; r++) {
        if (mex.count(a[r]))
            mex.erase(a[r]);

        int x;
        if (mex.size()) 
            x = *mex.begin();
        else 
            x = n + 1;

        if (x == suffix[l]) {
            b.pb(x);
            l = r + 1;

            mex.clear();
            for (int i = 0; i <= suffix[l]; i++) {
                mex.insert(i);
            }
        }
    }
    cout << b.size() << "\n";
    for (int &x: b) 
        cout << x << " ";
    
    cout << "\n";
}




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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}

