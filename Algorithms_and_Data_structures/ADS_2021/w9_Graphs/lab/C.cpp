// accepted
#include <bits/stdc++.h> 

using namespace std;

vector<int> g[11111];
bool used[11111]; 
int n, c;

int dfs(int v) {
    used[v] = true;
    int k = 1;
    for (auto i: g[v]) {
        if (used[i] == false) {
            k += dfs(i);
        }
    }
    return k;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> c;
    c--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < g[i].size(); j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dfs(c);

    return 0;
}