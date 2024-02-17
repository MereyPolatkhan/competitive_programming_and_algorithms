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

 
bool cmp(vector<ll> &a, vector<ll> &b) {
    return a.size() > b.size();
}

void solve() {  
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)     
        cin >> a[i];
    for (int i = 0; i < n; i++)     
        cin >> b[i];

    map<int, vector<ll> > mp;

    for (int i = 0; i < n; i++) {
        mp[a[i]].pb(b[i]);
    }

    for (auto &it: mp) {
        sort(rall(it.second));
        for (int i = 1; i < it.second.size(); i++) {
            it.second[i] += it.second[i - 1];
        }
    }

    vector<vector<ll>> c;

    for (auto &it: mp)
        c.pb(it.second);
    
    sort(all(c), &cmp);

    vector<ll> res(n);
    for (int k = 1; k <= n; k++) {
        
        ll sum = 0;

        for (vector<ll> &v: c) {
            if (v.size() < k) 
                break;
            int index = v.size() - (v.size() % k);
            sum += v[index - 1];
        }

        // cout << "k: " << k << " ";
        // cout << "sum: " << sum << "\n";

        res[k - 1] = sum;
    }   
    
    for (ll &x: res)    
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

