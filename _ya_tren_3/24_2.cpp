#include <bits/stdc++.h>


using namespace std;

vector<int> dp(10000, 1e9);
vector<int> a(10000, 0);
vector<int> b(10000, 0);
vector<int> c(10000, 0);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }


    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = min(a[1] + a[2], b[1]);
    
    for (int i = 3; i <= n; i++) {
        dp[i] = min({
            dp[i - 1] + a[i], 
            dp[i - 2] + b[i - 1], 
            dp[i - 3] + c[i - 2]});
    }
    

    cout << dp[n];
    return 0;
}