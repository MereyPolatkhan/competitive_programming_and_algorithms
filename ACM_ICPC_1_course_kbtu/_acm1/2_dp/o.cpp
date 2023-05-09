#include <bits/stdc++.h>

using namespace std;

int dp[10000][10000];

int main(){

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    
    int i = n, j = m;
    string res = "";
    while (i >= 1 and j >= 1) {
        if (s1[i - 1] == s2[j - 1]) {
            // cout << s1[i - 1] << " ";
            res += s1[i - 1];
            i = i - 1;
            j = j - 1;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i = i - 1;
                j = j;
            }
            else {
                i = i;
                j = j - 1;
            }
        }
    }

    reverse(res.begin(), res.end());

    cout << res;

    return 0;
}