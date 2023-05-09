#include <bits/stdc++.h>

using namespace std;

#define M 300011

vector<int> dp(M, 1e9);

void generate_dp() {
    vector<int> a;
    int i = 1;
    int s1 = 0;
    int s2 = 0;

    while (s2 <= M) {
        s1 += i;
        i++;
        s2 += s1;
        a.push_back(s2);
    }


    dp[0] = 0;

    for (int i = 1; i <= M - 10; i++) {
        for (auto j : a) {
            if (i < j) {
                break;
            }
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // freopen("balls.in", "r", stdin);
    // freopen("balls.out", "w", stdout);

    generate_dp();

    int t;
    cin >> t;
    while (t--){ 
        int m;
        cin >> m;
        cout << dp[m] << "\n";
    }




    return 0;
}