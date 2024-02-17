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


using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, sum = 0;
    cin >> n >> sum;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(sum + 1, (int)1e9);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        for (int c: a) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }   
        }
    }
    if (dp[sum] == 1e9) 
        cout << -1 << "\n";
    else 
        cout << dp[sum] << "\n";


    return 0;
}