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

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(all(b));
    map<int, vector<int>> mpa, mpb;

    for (int i = 0; i < n; i++) {
        mpa[a[i]].pb(i);
        mpb[b[i]].pb(i);
    }

    for (int i = 1; i <= (int)1e5; i++) {
        if (!mpa[i].size() or !mpb[i].size())
            continue;

        int cntOdd = 0, cntEven = 0;
        for (int x: mpa[i]) {
            if (x % 2)
                cntOdd++;
            else 
                cntEven++;
        }


        for (int y: mpb[i]) {
            if (y % 2) 
                cntOdd--;
            else    
                cntEven--;
        }


        if (cntEven == 0 and cntOdd == 0) {
            continue;
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}   




int main() { 
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