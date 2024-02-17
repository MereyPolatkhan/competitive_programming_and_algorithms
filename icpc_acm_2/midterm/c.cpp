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

int const N = 1e3 + 7;
int const MAX_W = 1e5 + 7;

int dp[N][MAX_W];

void solve() {
    int n, max_price;
    cin >> n >> max_price; 

    vector<int> price(n + 1), num(n + 1);

    for (int i = 1; i <= n; i++) 
        cin >> price[i];
    
    for (int i = 1; i <= n; i++) 
        cin >> num[i];
    

    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= max_price; s++) {
            if (s >= price[k]) {
                dp[k][s] = max(dp[k - 1][s], dp[k - 1][s - price[k]] + num[k]);
            }
            else {
                dp[k][s] = dp[k - 1][s];
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= max_price; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    cout << dp[n][max_price] << "\n";

}


int main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    

    return 0;

}

