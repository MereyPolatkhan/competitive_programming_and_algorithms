#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    int g[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }


    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (g[i][j] == 1) {
                a.push_back({i + 1, j + 1});
            }
        }
    }

    for (auto i: a) cout << i.first << " " << i.second << "\n";

    return 0;
}