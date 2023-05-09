#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;


    for (int k = 0; k < t; k++) {
        map<string, int> m;
        vector<vector<string>> a(3);
        int n;
        cin >> n;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                string s;
                cin >> s;
                a[i].push_back(s);
                m[s]++;
            }
        }

        for (int i = 0; i < 3; i++) {
            int res = 0;
            for (int j = 0; j < n; j++) {
                if (m[a[i][j]] == 3) {
                    res += 0;
                }
                if (m[a[i][j]] == 2) {
                    res += 1;
                }
                if (m[a[i][j]] == 1) {
                    res += 3;
                }
            }
            cout << res << " ";
        }
        cout << "\n";
    }

    // for (auto i: m) cout << i.first << " " << i.second << endl;
    // cout << endl;
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}