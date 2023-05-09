#include <bits/stdc++.h>

using namespace std;

vector<int> g[100007];
int used[1000007];

void print(int n){
    for (int i = 0; i < n; i++) {
        cout << i + 1<< "--------";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j]  + 1<< " ";
        }
        cout << "\n";
    }
}

set<int> s;

void dfs(int c) {
    used[c] = 1;
    for (auto el: g[c]) {
        s.insert(el);
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
    // print(n);

    int c = 0;
    s.insert(c);
    dfs(c);

    
    cout << s.size() << "\n";
    for (auto i: s) cout << i + 1 << " " ;


    return 0;
}