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
    string s;
    cin >> s;

    reverse(all(s));
    int zero_cnt = count(all(s), '0');

    vector<ll> res;

    int j = 0;
    ll sum1 = 0;
    ll sum0 = 0;
    for (int i = 0; i < n; i++) {
        if (zero_cnt < i + 1) {
            res.pb(-1);
            continue;
        }
        
        if (s[i] == '1') {
            if (j < i)
                j = i;
            while (j < n and s[j] == '1') {
                j++;
            }
            swap(s[i], s[j]);

            sum0 += j;
            sum1 += i;
        }
        
        res.pb(sum0 - sum1);
    }

    for (ll i: res) {
        cout << i << " ";
    }
    cout << "\n";
}   



int main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
