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


void result(vector<int> &a) {
    int cnt = 0;
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i - 1] > a[i] and a[i] < a[i + 1]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    
    cout << "\n";
}
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(rall(a));

    vector<int> b(n);

    int i = 0;
    for (int j = 0; j < n; j += 2) {
        b[j] = a[i++];
    }    
    for (int j = 1; j < n; j += 2) {
        b[j] = a[i++];
    }    

    result(b);
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
