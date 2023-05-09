#include <bits/stdc++.h>

using namespace std;

vector<int> g[10000];
int color[10000];

bool flag = true;

void dfs(int v, int c) {
    color[v] = c;
    for (auto i: g[v]) {
        if (color[i] == 0) {
            dfs(i, 3 - c);
        }
        else {
            if (color[i] == c) {
                flag = false;
                return;
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0){ 
            dfs(i, 1);
        }
    }
    
    if (flag) cout << "YES\n";
    else {
        cout << "NO"; 
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 1) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}