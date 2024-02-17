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

int calc(int b) {
    int cnt = (int)log2(b);
    int a = (int)pow(2, cnt);

    while (a < b) {
        int d = b - a;
        int x = (a + d - 1) / d;
        d = a / x;
        a += d;
        cnt++;
    }
    
    return cnt; 
}  

void solve() {
    int n, max_price;
    cin >> n >> max_price;

    vector<int> b(n + 1), coin(n + 1), price(n + 1, 0);

    for (int i = 1; i <= n; i++) 
        cin >> b[i];

    for (int i = 1; i <= n; i++) 
        cin >> coin[i];

    for (int i = 1; i <= n; i++) 
        price[i] = calc(b[i]);


    max_price = min(max_price, n * 12);

    vector<int> dp(max_price + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = max_price; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + coin[i]);
        }
    }

    cout << dp[max_price] << "\n";

}

int32_t main() { 
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
