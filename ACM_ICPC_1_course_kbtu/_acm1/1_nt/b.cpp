#include <bits/stdc++.h>

using namespace std;

void solve() {

    int sum;
    cin >> sum;
    
    vector<int> ans;

    for (int n = 2; n <= sqrt(2 * sum); n++) {
        if (2 * sum % n == 0) {
            if (((2 * sum / n) - n + 1) % 2 == 0) {
                int a1= ((2 * sum / n) - n + 1) / 2;
                for (int j = 0; j < n; j++) {
                    ans.push_back(a1);
                    a1++;
                }
                break;
            }
        }
    }

    if (ans.size() == 0) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << sum << " = ";
        for (int i = 0; i < ans.size(); i++) {
            if (i != ans.size() - 1) {
                cout << ans[i] << " + ";
            }
            else {
                cout << ans[i];
            }
        }
    }

    cout << "\n";

}

int main() {
    // freopen("input.txt", "r", stdin);

    long long t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}