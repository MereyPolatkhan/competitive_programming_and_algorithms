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

    vector< pair<int, char> > a;
    for (int i = 0; i < n; i++) { 
        int x;
        cin >> x;
        a.pb({x, 'b'});
    }
    for (int i = 0; i < n; i++) { 
        int x;
        cin >> x;
        a.pb({x, 'r'});
    }
    
    sort(all(a));


    // continue your idea

    vector<int> blue, red;
    int cnt = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i].second == 'b') {
            cnt++;
        }
        else {
            cnt--;
        }
        blue.pb(cnt);
    }

    cnt = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i].second == 'r') {
            cnt--;
        }
        else {
            cnt++;
        }
        red.pb(cnt);
    }


    int from = *max_element(all(red));
    int till = n - *max_element(all(blue));
    cout << till - from + 1 << "\n";
    for (int i = from; i <= till; i++) {
        cout << i << " ";
    }

    return;
    for (auto i : a) cout << i.first << " "; cout << "\n";
    for (auto i : a) cout << i.second << " "; cout << "\n";
    for (int i : blue) cout << i << " "; cout << "\n";
    for (int i : red) cout << i << " "; cout << "\n\n\n\n";
}

/*


4
10 20 30 40
11 15 25 26


4
6 7 8 10
1 2 3 9


4
10 20 30 40
5 15 25 35

4
10 20 30 40
1 2 51 52


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
    }

    return 0;
}

