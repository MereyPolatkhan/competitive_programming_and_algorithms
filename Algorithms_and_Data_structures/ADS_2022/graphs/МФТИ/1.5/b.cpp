#include <bits/stdc++.h>

using namespace std;

vector<int> g[100007];
int used[1000007];


vector<vector<int>> res;
vector<int> cur;

void dfs(int c) {
    used[c] = 1;
    cur.push_back(c);
    for (auto el: g[c]) {
        if (used[el] == 0) {
            dfs(el);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i);
            sort(cur.begin(), cur.end());
            res.push_back(cur);
            cur.clear();
        }
    }

    cout << res.size() << "\n";
    for (auto i: res) {
        cout << i.size() << "\n";
        for (auto y: i) {
            cout << y + 1<< " ";
        }
        cout << "\n";
    }

    return 0;
}